//
//  BlockManager.cpp
//  BlockGame
//
//  Created by Coody on 2016/10/6.
//
//

#include "BlockManager.h"

USING_NS_CC;

bool BlockManager::init(){
    
    if ( CCNode::init() ) {
        
        m_uiBlockMaxNumber = 35;
        m_uiBlockMaxMoveNumber = 2;
        m_uiRecentTargetNumber = 1;
        
        
        
        return true;
    }
    
    return false;
}
