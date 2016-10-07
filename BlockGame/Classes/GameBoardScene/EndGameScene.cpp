//
//  EndGameScene.cpp
//  BlockGame
//
//  Created by Coody on 2016/10/7.
//
//

#include "EndGameScene.h"

// for Constant
#include "BlockGameConstant.h"

USING_NS_CC;

bool EndGameLayer::init(){
    
    if ( CCLayerColor::initWithColor( D_BlockGame_BackgroundColor ) ) {
        
        
        
        return true;
    }
    
    return false;
}
