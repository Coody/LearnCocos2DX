//
//  StartMenuScene.cpp
//  BlockGame
//
//  Created by Coody on 2016/9/30.
//
//

#include "StartMenuScene.h"

// for Manager (Layer)
#include "StartMenuManager.h"

USING_NS_CC;

#pragma mark - Public
CCScene *StartMenuLayer::scene(){
    
    CCScene *scene = CCScene::create();
    
    StartMenuManager *startMenuMgr = StartMenuManager::create();
    
    startMenuMgr->startTitleHeartBeat();
    
    scene->addChild(startMenuMgr);
    
    
    return scene;
    
}

