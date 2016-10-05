//
//  StartMenuScene.h
//  BlockGame
//
//  Created by Coody on 2016/9/30.
//
//

#ifndef StartMenuScene_h
#define StartMenuScene_h

#include "cocos2d.h"

typedef enum{
    EnumStartMenuSceneTag_Man = 10,
    EnumStartMenuSceneTag_GameBoard = 15,
    EnumStartMenuSceneTag_Finger = 20,
    EnumStartMenuSceneTag_MenuButton = 100
}EnumStartMenuSceneTag;

class StartMenuLayer : public cocos2d::CCLayerColor{
public:
    
    virtual bool init();
    
    static cocos2d::CCScene *scene();
    
    CREATE_FUNC(StartMenuLayer);
    
private:
    
    void createGameTitle();
    
    void createManAnimation();
    
    void createGameBoardAnimation();
    
    void createMenuButton();
    
    void selectedMenuButton();
    
    void changeScene();
};

#endif /* StartMenuScene_hpp */
