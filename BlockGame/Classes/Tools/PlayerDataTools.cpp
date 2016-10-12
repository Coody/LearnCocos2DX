//
//  PlayerDataTools.cpp
//  BlockGame
//
//  Created by Chou Coody on 2016/10/11.
//
//

#include "PlayerDataTools.h"

#include "LeaderboardData.h"

USING_NS_CC;

#pragma mark - Public
static PlayerDataTools *instance = NULL;

PlayerDataTools *PlayerDataTools::sharedInstance(){
    if ( instance == NULL ) {
        instance = PlayerDataTools::create();
        instance->retain();
    }
    return instance;
}

bool PlayerDataTools::init(){
    if ( CCNode::init() ) {
        
        m_arrLeaderboardDataArray = CCArray::create();
        m_arrLeaderboardDataArray->retain();
        
#define D_Test
#ifdef D_Test
        for (int i = 0 ; i < 5 ; i++ ) {
            LeaderboardData *unit = LeaderboardData::create();
            unit->setNameAndScore(CCString::create("Test01"), 1000);
            m_arrLeaderboardDataArray->addObject(unit);
        }
#endif
        
        return true;
    }
    return false;
}

void PlayerDataTools::savePlayer(cocos2d::CCString *name , int score ){
    LeaderboardData *playerData = LeaderboardData::create();
    playerData->setNameAndScore( name , score);
    m_arrLeaderboardDataArray->addObject(playerData);
    this->sequenceData();
}

CCArray *PlayerDataTools::getPlayerDataArray(){
    return m_arrLeaderboardDataArray;
}

#pragma mark - Private
//void PlayerDataTools::release(){
//    leaderboardDataArray->removeAllObjects();
//    leaderboardDataArray->release();
//    leaderboardDataArray = NULL;
//}

void PlayerDataTools::sequenceData(){
    
    if ( m_arrLeaderboardDataArray->count() <= 1  ) {
        return;
    }
    
    for ( int i = m_arrLeaderboardDataArray->count() - 1 ; i >= 1 ; i++) {
        
        LeaderboardData *unit1 = (LeaderboardData *)m_arrLeaderboardDataArray->objectAtIndex(i);
        LeaderboardData *unit2 = (LeaderboardData *)m_arrLeaderboardDataArray->objectAtIndex(i-1);
        if ( unit1->getScore() >= unit2->getScore() ) {
            m_arrLeaderboardDataArray->exchangeObjectAtIndex(i, i-1);
        }
        else{
            break;
        }
        
    }
    
}
