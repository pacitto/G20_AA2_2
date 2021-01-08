#include "Map2Scene.h"

Map2Scene::Map2Scene()
{
    state = SceneStates::MAP2_RUNNING;
    backgroundId = GAME::BACKGROUND_ID;
    backgroundRect = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
    player1 = new Player(1);
    player2 = new Player(2);
    InitMap();
    ReadConfig();
}

void Map2Scene::InitMap()
{
    map = new char* [WIDTH];
    for (int i = 0; i < WIDTH; i++)
    {
        map[i] = new char[HEIGHT];
        for (int j = 0; j < HEIGHT; j++)
        {
            map[i][j] = ' ';
        }
    }
}

void Map2Scene::ReadConfig()
{
    rapidxml::xml_document<> doc;
    std::ifstream file("../../res/files/config.xml");
    std::stringstream buffer;
    buffer << file.rdbuf();
    file.close();
    std::string content(buffer.str());
    doc.parse<0>(&content[0]);

    rapidxml::xml_node<>* pRoot = doc.first_node();
    rapidxml::xml_node<>* pNode = pRoot->first_node("Level1");
    pNode = pNode->next_sibling();
    rapidxml::xml_node<>* pNodeI = pNode->first_node("Players");
    rapidxml::xml_node<>* pNodeII = pNodeI->first_node("Player1");
    rapidxml::xml_node<>* pNodeIII = pNodeII->first_node("Positon");

    //player1
    rapidxml::xml_attribute<>* pAttr = pNodeII->first_attribute();
    player1->SetLives(std::atoi(pAttr->value()));
    pAttr = pNodeIII->first_attribute();
    player1->SetInitialPos({ std::atoi(pAttr->value()), std::atoi(pAttr->next_attribute()->value()) });
    map[player1->GetInitialPos().x][player1->GetInitialPos().y] = '1';

    //player2
    pNodeII = pNodeII->next_sibling();
    pNodeIII = pNodeII->first_node("Positon");
    pAttr = pNodeII->first_attribute();
    player2->SetLives(std::atoi(pAttr->value()));
    pAttr = pNodeIII->first_attribute();
    player2->SetInitialPos({ std::atoi(pAttr->value()), std::atoi(pAttr->next_attribute()->value()) });
    map[player2->GetInitialPos().x][player2->GetInitialPos().y] = '2';
   
    //map
    pNodeI = pNodeI->next_sibling();
    for (pNodeII = pNodeI->first_node(); pNodeII; pNodeII = pNodeII->next_sibling())
    {
        pAttr = pNodeII->first_attribute();
        if (pAttr->value_size() == 5)
        {
            pAttr = pAttr->next_attribute();
            map[std::atoi(pAttr->value())][std::atoi(pAttr->next_attribute()->value())] = 'W';
        }
        else
        {
            pAttr = pAttr->next_attribute();
            map[std::atoi(pAttr->value())][std::atoi(pAttr->next_attribute()->value())] = 'B';
        }
    }


    std::cout << "Player 1 lives: " << player1->GetLives() << ", player 1 pos: " << player1->GetInitialPos().x << ", " << player1->GetInitialPos().y << std::endl;
    std::cout << "Player 2 lives: " << player2->GetLives() << ", player 2 pos: " << player2->GetInitialPos().x << ", " << player2->GetInitialPos().y << std::endl << std::endl;
    std::cout << "Map: " << std::endl;
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            std::cout << map[j][i] << "  ";
        }
        std::cout << std::endl;
    }

}

void Map2Scene::Update(bool* _inputs, VEC2 _mousePos)
{
}

void Map2Scene::Draw()
{
    Renderer::Instance()->Clear();
    Renderer::Instance()->PushImage(backgroundId, backgroundRect);
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            if (map[j][i] == 'W')
            {
                Renderer::Instance()->PushSprite(ITEMS_SPRITESHEET::ID, RECT{ 0, 0, ITEMS_SPRITESHEET::SIZE, ITEMS_SPRITESHEET::SIZE }, RECT{ j * ITEMS_SPRITESHEET::SIZE + OFFSET_X, i * ITEMS_SPRITESHEET::SIZE + OFFSET_Y , ITEMS_SPRITESHEET::SIZE, ITEMS_SPRITESHEET::SIZE });
            }
            else if (map[j][i] == 'B')
            {
                Renderer::Instance()->PushSprite(ITEMS_SPRITESHEET::ID, RECT{ ITEMS_SPRITESHEET::SIZE, 0, ITEMS_SPRITESHEET::SIZE, ITEMS_SPRITESHEET::SIZE }, RECT{ j * ITEMS_SPRITESHEET::SIZE + OFFSET_X, i * ITEMS_SPRITESHEET::SIZE + OFFSET_Y , ITEMS_SPRITESHEET::SIZE, ITEMS_SPRITESHEET::SIZE });
            }
        }
    }

    player1->Draw();
    player2->Draw();

    Renderer::Instance()->Render();
}

Map2Scene::~Map2Scene()
{
}