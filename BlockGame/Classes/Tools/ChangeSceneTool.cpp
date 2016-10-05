//
//  ChangeSceneTool.cpp
//  BlockGame
//
//  Created by Coody on 2016/9/30.
//
//

#include "ChangeSceneTool.h"

ChangeSceneTool *ChangeSceneTool::s_instance = 0;

ChangeSceneTool *ChangeSceneTool::sharedInstance(){
    
    if ( s_instance == 0 ) {
        s_instance = new ChangeSceneTool( EnumChangeSceneToolType_StartMenuScene );
    }
    return s_instance;
}


