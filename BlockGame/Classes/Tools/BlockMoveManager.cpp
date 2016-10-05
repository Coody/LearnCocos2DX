//
//  BlockMoveManager.cpp
//  BlockGame
//
//  Created by Coody on 2016/10/3.
//
//

#include "BlockMoveManager.h"

USING_NS_CC;

bool BlockMoveManager::initWithArray( cocos2d::CCArray *originalArray ){
    
    if ( CCNode::init() ) {
        
        this->resetFirstArray(originalArray);
        
        return true;
    }
    
    return false;
}


void BlockMoveManager::resetFirstArray( cocos2d::CCArray *originalArray){
    
    this->releaseDics();
    
    m_dRecentDic = CCDictionary::create();
    m_dRecentDic->retain();
    for ( int i = 0 ; i < originalArray->count() ; i++ ) {
        BasicBlock *block = (BasicBlock *)originalArray->objectAtIndex(i);
        CCString *blockNumber = CCString::createWithFormat("%d" , block->getBlockNumber() );
        m_dRecentDic->setObject( blockNumber , block->getBlockPoint() );
    }
    m_dFutureDic = CCDictionary::createWithDictionary(m_dRecentDic);
    m_dFutureDic->retain();
}

// 查詢是否可走？
bool BlockMoveManager::canGo( unsigned int position ){
    bool checkCanGo = false;
//    CCString *recentPosition = (CCString *)m_dRecentDic->objectForKey(position);
    CCString *featurePosition = (CCString *)m_dFutureDic->objectForKey(position);
    if ( featurePosition == NULL ) {
        checkCanGo = true;
    }
    return checkCanGo;
}

// 導航走向（會選個位置，如果沒辦法走，回傳 -1 ）
int BlockMoveManager::gpsGo( unsigned int recentPoint ){
    int goPosition = -1;
    CCArray *array = CCArray::create( CCString::create("6") , CCString::create("1") , CCString::create("-1") , CCString::create("-6") , NULL );
    for (int i = 0 ; i < 5 ; i++ ) {
        unsigned int indexA = arc4random()%4;
        unsigned int indexB = arc4random()%4;
        array->exchangeObjectAtIndex(indexA, indexB);
    }
    
    for (int i = 0 ; i < 4 ; i++ ) {
        
        int addPosition = ((CCString *)array->objectAtIndex(i))->intValue();
        if ( addPosition == 1 && recentPoint%D_BlockGame_GameBoardWidth == 5) {
            // 超過邊界
            continue;
        }
        else if( addPosition == -1 && recentPoint%D_BlockGame_GameBoardWidth == 0){
            // 超過邊界
            continue;
        }
        
        int newPosition = recentPoint + addPosition;
        if ( newPosition >= 0 && 
            newPosition < D_BlockGame_GameBoardMax && 
            this->canGo( newPosition ) ) {
            goPosition = newPosition;
            m_dFutureDic->setObject( m_dRecentDic->objectForKey(recentPoint) , goPosition);
            m_dFutureDic->removeObjectForKey(recentPoint);
            break;
        }
    }
    return goPosition;
}

void BlockMoveManager::synchronizeDic(){
    
    m_dRecentDic->removeAllObjects();
    m_dRecentDic->release();
    m_dRecentDic = CCDictionary::createWithDictionary(m_dFutureDic);
    m_dRecentDic->retain();
    
#ifdef D_Dev_Ver
    this->showRecent();
    this->showFeature();
#endif
}

void BlockMoveManager::addNewBlock( BasicBlock *block ){
    // TODO:
}

void BlockMoveManager::removeBlock( BasicBlock *block ){
    
    BasicBlock *futureBlock = (BasicBlock *)m_dRecentDic->objectForKey( block->getBlockPoint() );
    if ( futureBlock != NULL ) {
#ifdef D_Dev_Ver
        CCLOG(" 移除 %d !!" , block->getBlockNumber() );
#endif
        m_dFutureDic->removeObjectForKey( block->getBlockPoint() );
    }
    
    BasicBlock *recentBlock = (BasicBlock *)m_dRecentDic->objectForKey( block->getBlockPoint() );
    if ( recentBlock != NULL ) {
#ifdef D_Dev_Ver
        CCLOG(" 移除 %d !!" , block->getBlockNumber() );
#endif
        m_dRecentDic->removeObjectForKey( block->getBlockPoint() );
    }
}

void BlockMoveManager::releaseDics(){
    if ( m_dRecentDic != NULL ) {
        m_dRecentDic->removeAllObjects();
        m_dRecentDic = NULL;
    }
    if ( m_dFutureDic != NULL ) {
        m_dFutureDic->removeAllObjects();
        m_dFutureDic = NULL;
    }
}

#ifdef D_Dev_Ver
void BlockMoveManager::showRecent(){
    CCLOG("\n Feature : ");
    int baseNumber = (D_BlockGame_GameBoardMax - D_BlockGame_GameBoardWidth);
    for ( int i = 0 ; i <= D_BlockGame_GameBoardWidth - 1 ; ) {
        
        CCString *value = (CCString *)m_dRecentDic->objectForKey(baseNumber + i);
        
        if ( value == NULL ) {
            printf( " 0" );
        }
        else{
            printf( "%2d" , value->intValue() );
        }
        
        if ( i == D_BlockGame_GameBoardWidth - 1 ) {
            printf( "\n" );
            i = 0;
            baseNumber = baseNumber - D_BlockGame_GameBoardWidth;
            if ( baseNumber < 0 ) {
                break;
            }
        }
        else{
            printf( "," );
            i++;
        }
    }
}

void BlockMoveManager::showFeature(){
    CCLOG("\n Feature : ");
    int baseNumber = (D_BlockGame_GameBoardMax - D_BlockGame_GameBoardWidth);
    for ( int i = 0 ; i <= D_BlockGame_GameBoardWidth - 1 ; ) {
        
        CCString *value = (CCString *)m_dFutureDic->objectForKey(baseNumber + i);
        
        if ( value == NULL ) {
            printf( " 0" );
        }
        else{
            printf( "%2d" , value->intValue() );
        }
        
        if ( i == D_BlockGame_GameBoardWidth - 1 ) {
            printf( "\n" );
            i = 0;
            baseNumber = baseNumber - D_BlockGame_GameBoardWidth;
            if ( baseNumber < 0 ) {
                printf( "\n\n" );
                break;
            }
        }
        else{
            printf( "," );
            i++;
        }
    }
}
#endif


