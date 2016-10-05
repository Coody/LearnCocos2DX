//
//  LevelScene.h
//  BlockGame
//
//  Created by Coody on 2016/9/30.
//
//

#ifndef LevelScene_h
#define LevelScene_h

#include "cocos2d.h"

// for Constant
#include "BlockGameConstant.h"

typedef enum{
    EnumLevelSceneTag_TitleLabel = 10,
    EnumLevelSceneTag_MenuButton_Easy = 20,
    EnumLevelSceneTag_MenuButton_Normal = 30,
    EnumLevelSceneTag_MenuButton_Hard = 40
}EnumLevelSceneTag;

class LevelLayer : public cocos2d::CCLayerColor{
    
public:
    
    virtual bool init();
    
    static cocos2d::CCScene *scene();
    
    CREATE_FUNC(LevelLayer);
  
private:
    
    void showLabelAnimation();
    
    void hideLabelAnimation();
    
    void showMenuButtonAnimation();
    
    void hideMenuButtonAnimation();
    
    void selectLevelEasy();
    void selectLevelNormal();
    void selectLevelHard();
    
    void changeScene();
    
    void setMenuTouchDisable();
    
    EnumGameBoard_Level m_enumLevel;
};

#endif /* LevelScene_h */
