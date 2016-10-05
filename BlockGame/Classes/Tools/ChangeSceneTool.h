//
//  ChangeSceneTool.h
//  BlockGame
//
//  Created by Coody on 2016/9/30.
//
//

#ifndef ChangeSceneTool_h
#define ChangeSceneTool_h

#include <stdio.h>

typedef enum{
    EnumChangeSceneToolType_LogoScene = 0,
    EnumChangeSceneToolType_StartMenuScene,
    EnumChangeSceneToolType_LevelScene,
    EnumChangeSceneToolType_GameBoardScene
}EnumChangeSceneToolType;

class ChangeSceneTool{
public:
    
    static ChangeSceneTool *sharedInstance();
    
    void changeSceneWithType( EnumChangeSceneToolType type );
    
private:
    
    ChangeSceneTool( EnumChangeSceneToolType startSceneType );
//    ChangeSceneTool( ChangeSceneTool const& );
//    void operator=(ChangeSceneTool const&);
    
    static ChangeSceneTool *s_instance;
    
    EnumChangeSceneToolType m_enumRecentSceneType;
    
};

#endif /* ChangeSceneTool_hpp */
