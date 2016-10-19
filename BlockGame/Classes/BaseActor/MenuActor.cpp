//
//  MenuActor.cpp
//  BlockGame
//
//  Created by Coody on 2016/10/18.
//
//

#include "MenuActor.h"

USING_NS_CC;

bool MenuActor::initWithSetting(cocos2d::CCString *titleString, const char *fontName, float fontSize){
    
    if ( CCNode::create() ) {
        
        this->setAnchorPoint(ccp(0.5, 0.5));
        
        
        
        return true;
    }
    
    return false;
}

cocos2d::CCPoint getMoveInActionStartPosition(){
    
}

void startMoveInAction(){
    
}

void startMoveOutAction(){
    
}


