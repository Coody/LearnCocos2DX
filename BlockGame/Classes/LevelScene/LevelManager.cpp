//
//  LevelManager.cpp
//  BlockGame
//
//  Created by Coody on 2016/10/18.
//
//

#include "LevelManager.h"

// for Constant
#include "BlockGameConstant.h"

USING_NS_CC;

LevelManager::LevelManager(){
    
}

LevelManager::~LevelManager(){
    
}

bool LevelManager::init(){
    if ( CCLayerColor::initWithColor(D_BlockGame_BackgroundColor) ) {
//        
//        // 建立 title
//        this->initialTitle();
//        
//        this->initialBackground();
//        
//        this->initialMenuButton();
//        
//        this->preloadSounds();
//        
//        this->playBGMusic();
        
        return true;
    }
    return false;
}