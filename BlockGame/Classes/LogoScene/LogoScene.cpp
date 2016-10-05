//
//  LogoScene.cpp
//  BlockGame
//
//  Created by Coody on 2016/9/30.
//
//

#include "LogoScene.h"

// for Constant
#include "BlockGameConstant.h"

USING_NS_CC;

bool LogoLayer::init(){
    
    if ( CCLayerColor::initWithColor(D_BlockGame_BackgroundColor) ) {
        
        
        
        return true;
    }
    
    return false;
}
