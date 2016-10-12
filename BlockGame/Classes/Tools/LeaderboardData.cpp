//
//  LeaderboardData.cpp
//  BlockGame
//
//  Created by Chou Coody on 2016/10/11.
//
//

#include "LeaderboardData.h"

USING_NS_CC;

bool LeaderboardData::init(){
    
    if ( CCNode::init() ) {
        
        
        m_iScore = 0;
        
        return true;
    }
    
    return false;
}


void LeaderboardData::setNameAndScore( cocos2d::CCString *name , int score ){
    m_sName = CCString::create( name->getCString() );
    m_sName->retain();
    m_iScore = score;
}

CCString *LeaderboardData::getName(){
    return m_sName;
}

int LeaderboardData::getScore(){
    return m_iScore;
}

