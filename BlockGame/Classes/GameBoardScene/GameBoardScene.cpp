//
//  GameBoardScene.cpp
//  BlockGame
//
//  Created by Chou Coody on 2016/10/3.
//
//

#include "GameBoardScene.h"

#include "BlockMoveManager.h"

USING_NS_CC;

#pragma mark - Public
bool GameBoardLayer::init(EnumGameBoard_Level level){
    
    if ( CCLayerColor::initWithColor( D_BlockGame_LevelLayerColor ) ) {
        
        m_bCanTouch = false;
        m_enumRecentLevel = level;
        m_uiRecentTargetNumber = 1;
        m_uiBlockMaxMoveNumber = 2;
        
        // 設定遊戲難度
        this->setGameLevel( m_enumRecentLevel );
        
        // 產生隨機的 block
        this->createBlocks();
        
        // 產生 Block Move 的 Manager
        BlockMoveManager *blockMoveManager = BlockMoveManager::create( m_arrBlockArray );
        this->addChild(blockMoveManager , EnumGameBoardSceneTag_BlockMoveManager , EnumGameBoardSceneTag_BlockMoveManager);
        
        // 畫面動畫開始
        this->startSceneAnimation();
        
        // 處理移動效果
        this->scheduleUpdate();
        
        return true;
    }
    
    return false;
}

CCScene *GameBoardLayer::scene(EnumGameBoard_Level level){
    
    CCScene *scene = CCScene::create();
    
    GameBoardLayer *layer = GameBoardLayer::create( level );
    
    scene->addChild(layer);
    
    return scene;
}

/**
 *  轉跳畫面後，開始的棋盤動畫
 */
void GameBoardLayer::startSceneAnimation(){
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    
    CCSprite *topMenuSprite = CCSprite::create( "topBar.png" );
    topMenuSprite->setPosition(ccp( visibleSize.width*0.5 , visibleSize.height + topMenuSprite->getContentSize().height*0.5 ));
    this->addChild(topMenuSprite , EnumGameBoardSceneTag_TopBar , EnumGameBoardSceneTag_TopBar);
    
    CCPoint targetPoint = ccp( visibleSize.width*0.5 , 940 + topMenuSprite->getContentSize().height*0.5 );
    
    CCMoveTo *moveToAction = CCMoveTo::create(0.3f, ccp(targetPoint.x, targetPoint.y - 30));
    CCEaseOut *easeOut = CCEaseOut::create(moveToAction, 1.4f);
    CCMoveBy *moveByAction = CCMoveBy::create(0.15f, ccp(0 , 30));
    CCEaseIn *easeIn = CCEaseIn::create(moveByAction, 1.4f);
    
    CCDelayTime *delay = CCDelayTime::create(0.1f);
    
    /**
     *  接續 Title 出現動畫
     */
    CCCallFunc *funcAction = CCCallFunc::create(this, callfunc_selector(GameBoardLayer::showRecentTargetTitle));
    CCSequence *sequenceAction = CCSequence::create( delay , easeOut , delay , easeIn , funcAction , NULL);
    topMenuSprite->runAction(sequenceAction);
}

void GameBoardLayer::initialBlocks( unsigned int count ){
    
    if( count > D_BlockGame_BlockMaxCount ){
        count = D_BlockGame_BlockMaxCount;
    }
    if ( count < 10 ) {
        count = 10;
    }
    
    for ( int i = 0 ; i < count ; i++ ) {
        
        BasicBlock *block = (BasicBlock *)m_arrBlockArray->objectAtIndex(i);
        this->addChild(block , EnumGameBoardSceneTag_Block , EnumGameBoardSceneTag_Block);
        
        // 掉下動畫接連的延遲速度
        CCDelayTime *delayTime = CCDelayTime::create(0.25*(i+1));
        CCCallFuncN *funcAction = CCCallFuncN::create( this , callfuncN_selector(GameBoardLayer::showBlockAnimation));
        
        
        if ( i >= count -1 ) {
            CCDelayTime *delayLittleTime = CCDelayTime::create(0.5f);
            CCCallFunc *funcFinishAction = CCCallFunc::create( this , callfunc_selector(GameBoardLayer::playTargetNumberAppearAnimation));
            CCCallFunc *funcReadyGoAction = CCCallFunc::create(this , callfunc_selector(GameBoardLayer::playReadyAnimation));
            block->runAction(CCSequence::create(delayTime , funcAction , delayLittleTime , funcFinishAction , delayLittleTime , funcReadyGoAction , NULL));
        }
        else{
            block->runAction(CCSequence::create(delayTime , funcAction , NULL));
        }
    }
    
}

#pragma mark - Private
CCPoint GameBoardLayer::getPointWithPosition( unsigned int position ){
    CCPoint targetPoint = ccp( 70 + 100*(position%6) , 70 + 100*((int)(position/6)) );
    return targetPoint;
}

void GameBoardLayer::setGameLevel(EnumGameBoard_Level newLevel){
    
    switch (m_enumRecentLevel) {
        case EnumGameBoard_Level_Crazy:
        {
            m_uiBlockMaxNumber = 35;
            m_uiBlockMaxMoveNumber = 6;
        }
            break;
        case EnumGameBoard_Level_Hard:
        {
            m_uiBlockMaxNumber = 35;
            m_uiBlockMaxMoveNumber = 5;
        }
            break;
        case EnumGameBoard_Level_Normal:
        {
            m_uiBlockMaxNumber = 25;
            m_uiBlockMaxMoveNumber = 4;
        }
            break;
        case EnumGameBoard_Level_Easy:
        default:
        {
            m_uiBlockMaxNumber = 15;
            m_uiBlockMaxMoveNumber = 2;
        }
            break;
    }
}

void GameBoardLayer::createBlocks(){
    
    if ( m_arrBlockArray == NULL ) {
        m_arrBlockArray = CCArray::create();
        m_arrBlockArray->retain();
    }
    else{
//        for ( int i = 0 ; i < m_arrBlockArray->count() ; i++ ) {
//            BasicBlock *block = (BasicBlock *)m_arrBlockArray->objectAtIndex(i);
//            block->disappearBlock( true , this , GameBoardLayer::removeBlock( block->getBlockNumber) );
//        }
//        m_arrBlockArray->removeAllObjects();
    }
    
    // 產生 6*9 = 54 (預設 54 格，可於 define 設定) 個不同位置參數，然後洗牌
    CCArray *positionArray = CCArray::create();
    for (int i = 0 ; i < D_BlockGame_GameBoardMax ; i++) {
        positionArray->addObject( CCString::createWithFormat("%d" , i) );
    }
    for (int i = 0 ; i < 50; i++ ) {
        unsigned int randomNumberA = arc4random()%(positionArray->count());
        unsigned int randomNumberB = arc4random()%(positionArray->count());
        positionArray->exchangeObjectAtIndex(randomNumberA, randomNumberB);
    }
    
    // 產生 blocks
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    for (int i = 1 ; i <= m_uiBlockMaxNumber ; i++ ) {
        BasicBlock *block = BasicBlock::create( EnumBasicBlockType_Normal , i);
        block->setPointWithPosition( ((CCString *)(positionArray->objectAtIndex(i-1)))->intValue() );
        block->setPosition( ccp( block->getPositionX() , visibleSize.height + 60 ) );
        m_arrBlockArray->addObject(block);
    }
    
}


void GameBoardLayer::showRecentTargetTitle(){
    
    // 進入此 Scene 後，此方法只 run 一次
    
    CCSprite *topBar = (CCSprite *)this->getChildByTag(EnumGameBoardSceneTag_TopBar);
    
    CCLabelTTF *labelTTF = CCLabelTTF::create( "Target !", D_BlockGame_FontName2 , 80);
    labelTTF->setColor(ccBLACK);
    labelTTF->setPosition( ccp( topBar->getContentSize().width*0.5 + 10 , topBar->getContentSize().height - labelTTF->getContentSize().height - 30 ) );
    topBar->addChild(labelTTF , EnumGameBoardSceneTag_TopBar_TargetTitle , EnumGameBoardSceneTag_TopBar_TargetTitle);
    
    labelTTF->setScale(0.1f);
    labelTTF->setOpacity(0.0f);
    
    CCFadeIn *fadeInAction = CCFadeIn::create(0.25f);
    CCEaseOut *easeOutAction = CCEaseOut::create(fadeInAction, 0.3f);
    CCScaleTo *scaleBig = CCScaleTo::create(0.3f, 1.0f);
    CCEaseOut *easeOutBigAction = CCEaseOut::create(scaleBig, 0.3f);
    
    /**
     初始化 block 的內容
     */
    CCCallFunc *funcAction = CCCallFunc::create( this , callfunc_selector(GameBoardLayer::initialBlockAnimation));
    
    labelTTF->runAction(easeOutAction);
    labelTTF->runAction(CCSequence::create(easeOutBigAction , funcAction , NULL ));
}

void GameBoardLayer::initialBlockAnimation(){
    this->initialBlocks( m_uiBlockMaxNumber );
}

void GameBoardLayer::setTargetNumber( CCString *text ){
    
    if ( m_uiRecentTargetNumber > m_uiBlockMaxNumber ) {
        
    }
    else{
        m_uiRecentTargetNumber = text->uintValue();
    }
    
    CCSprite *topBar = (CCSprite *)this->getChildByTag(EnumGameBoardSceneTag_TopBar);
    
    CCLabelTTF *targetNumberTTF = (CCLabelTTF *)topBar->getChildByTag(EnumGameBoardSceneTag_TopBar_TargetNumber);
    if ( targetNumberTTF == NULL ) {
        targetNumberTTF = CCLabelTTF::create(CCString::createWithFormat("%d" , m_uiRecentTargetNumber)->getCString() ,
                                             D_BlockGame_FontName2,
                                             140);
        targetNumberTTF->setColor(ccBLACK);
        targetNumberTTF->setScale(15.0f);
        targetNumberTTF->setOpacity(0.0f);
        targetNumberTTF->setPosition( ccp( topBar->getContentSize().width*0.5, 35));
        topBar->addChild(targetNumberTTF , EnumGameBoardSceneTag_TopBar_TargetNumber , EnumGameBoardSceneTag_TopBar_TargetNumber);
        
        CCScaleTo *scaleSmallTargetNumberAction = CCScaleTo::create(0.4f, 0.5f);
        CCEaseOut *easeOutTargetNumberAction = CCEaseOut::create(scaleSmallTargetNumberAction, 0.7f);
        CCScaleTo *scaleBigTargetNumberAction = CCScaleTo::create(0.3f, 1.0f);
        CCDelayTime *delaySmallTime = CCDelayTime::create(0.1f);
        CCEaseIn *easeInTargetNumberAction = CCEaseIn::create(scaleBigTargetNumberAction, 0.7f);
        
        
        CCDelayTime *delay = CCDelayTime::create(0.4f);
        targetNumberTTF->runAction(CCSequence::create(delay ,
                                                      easeOutTargetNumberAction ,
                                                      delaySmallTime ,
                                                      easeInTargetNumberAction ,
                                                      NULL ));
        CCFadeIn *fadeInAction = CCFadeIn::create(0.25f);
        CCEaseOut *easeOutAction = CCEaseOut::create(fadeInAction, 0.3f);
        targetNumberTTF->runAction(CCSequence::create(delay , easeOutAction , NULL));
        
    }
    else{
        
        CCScaleTo *scaleBigTargetNumberAction = CCScaleTo::create(0.05f, 1.5f);
        CCEaseOut *easeOutTargetNumberAction = CCEaseOut::create(scaleBigTargetNumberAction, 0.7f);
        CCCallFuncN *callFuncN = CCCallFuncN::create( this , callfuncN_selector(GameBoardLayer::changeTargetNumberString));
        CCDelayTime *delaySmallTime = CCDelayTime::create(0.1f);
        CCScaleTo *scaleSmallTargetNumberAction = CCScaleTo::create(0.05f, 1.0f);
        CCEaseIn *easeInTargetNumberAction = CCEaseIn::create(scaleSmallTargetNumberAction, 0.7f);
        
        targetNumberTTF->runAction(CCSequence::create(easeOutTargetNumberAction ,
                                                      callFuncN,
                                                      delaySmallTime ,
                                                      easeInTargetNumberAction ,
                                                      NULL ));
    }
}

void GameBoardLayer::changeTargetNumberString( CCObject *object ){
    CCLabelTTF *targetNumberTTF = (CCLabelTTF *)object;
    if ( m_uiRecentTargetNumber > m_uiBlockMaxNumber ) {
        targetNumberTTF->setString( "Done!" );
        targetNumberTTF->setColor(ccRED);
    }
    else{
        targetNumberTTF->setColor(ccBLACK);
        targetNumberTTF->setString( (CCString::createWithFormat("%d" , m_uiRecentTargetNumber))->getCString() );
    }
    
}

void GameBoardLayer::playTargetNumberAppearAnimation(){
    
    this->setTargetNumber( CCString::createWithFormat("%d" , m_uiRecentTargetNumber) );
    
    CCSprite *topBar = (CCSprite *)this->getChildByTag(EnumGameBoardSceneTag_TopBar);
    CCLabelTTF *targetNumberTTF = (CCLabelTTF *)topBar->getChildByTag(EnumGameBoardSceneTag_TopBar_TargetNumber);
    
    CCMoveBy *moveUpAction = CCMoveBy::create(1.0f, ccp(0, 10));
    CCEaseInOut *easeInOutUpAction = CCEaseInOut::create(moveUpAction , 0.7f);
    CCMoveBy *moveDownAction = CCMoveBy::create(1.0f, ccp(0, -10));
    CCEaseInOut *easeInOutDownAction = CCEaseInOut::create(moveDownAction, 0.7f);
    
    CCRepeatForever *repeatForever2 = CCRepeatForever::create(CCSequence::create(easeInOutUpAction , easeInOutDownAction , NULL));
    
    //        CCScaleTo *scaleALittleBig = CCScaleTo::create(0.05, 1.2f);
    //        CCEaseIn *easeInAction = CCEaseIn::create(scaleALittleBig, 0.5f);
    //        CCScaleTo *scaleALittleSmall = CCScaleTo::create(0.05, 1.0f);
    //        CCEaseOut *easeOutHeartBitAction = CCEaseOut::create(scaleALittleSmall, 0.5f);
    //        CCDelayTime *delayALittleTime = CCDelayTime::create(0.5f);
    //        CCSequence *sequenceHeartBit = CCSequence::create(easeInAction , easeOutHeartBitAction , delayALittleTime , NULL);
    //        CCRepeatForever *repeatForever = CCRepeatForever::create(sequenceHeartBit);
    
    //        targetNumberTTF->runAction(repeatForever);
    targetNumberTTF->runAction(repeatForever2);
}

void GameBoardLayer::playReadyAnimation(){
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    
    // ready
    CCLabelTTF *readyTTF = CCLabelTTF::create(" Ready", D_BlockGame_FontName2 , 160);
    readyTTF->setColor(ccRED);
    readyTTF->setPosition( ccp(visibleSize.width*0.5, visibleSize.height*0.44) );
    readyTTF->setScale(0.7f);
    readyTTF->setOpacity(0.0f);
    this->addChild(readyTTF , EnumGameBoardSceneTag_Ready , EnumGameBoardSceneTag_Ready);
    
    CCScaleTo *scaleBigAction = CCScaleTo::create(0.3f, 1.0f);
    CCEaseOut *easeOutAction = CCEaseOut::create(scaleBigAction, 5.0f);
    CCFadeIn *fadeInAction = CCFadeIn::create(0.2f);
    CCDelayTime *delayTime = CCDelayTime::create(1.5f);
    CCDelayTime *delayFadeInTime = CCDelayTime::create(1.6f);
    CCScaleTo *scaleSmallAction = CCScaleTo::create(0.2f, 0.7f);
    CCEaseIn *easeInAction = CCEaseIn::create(scaleSmallAction, 5.0f);
    CCFadeOut *fadeOutAction = CCFadeOut::create(0.1f);
    
    CCCallFunc *funcAction = CCCallFunc::create( this , callfunc_selector(GameBoardLayer::playGoAnimation));
    
    CCSequence *sequenceReadyAction = CCSequence::create( delayTime , easeOutAction , delayTime , easeInAction , funcAction , NULL );
    CCSequence *sequenceFadeInOutAction = CCSequence::create( delayTime , fadeInAction , delayFadeInTime , fadeOutAction , NULL );
    
    readyTTF->runAction(sequenceReadyAction);
    readyTTF->runAction(sequenceFadeInOutAction);
}

void GameBoardLayer::playGoAnimation(){
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    
    // go
    CCLabelTTF *goTTF = CCLabelTTF::create( " Go!", D_BlockGame_FontName2 , 200 );
    goTTF->setColor(ccRED);
    goTTF->setPosition( ccp(visibleSize.width*0.5, visibleSize.height*0.44) );
    goTTF->setScale(0.7f);
    goTTF->setOpacity(0.0f);
    this->addChild( goTTF , EnumGameBoardSceneTag_Go , EnumGameBoardSceneTag_Go );
    
    CCScaleTo *scaleBigAction = CCScaleTo::create(0.2f, 1.0f);
    CCEaseOut *easeOutAction = CCEaseOut::create(scaleBigAction, 5.0f);
    CCFadeIn *fadeInAction = CCFadeIn::create(0.15f);
    CCDelayTime *delayTime = CCDelayTime::create(1.0f);
    CCDelayTime *delayFadeInTime = CCDelayTime::create(1.6f);
    CCScaleTo *scaleSmallAction = CCScaleTo::create(0.1f, 0.0f);
    CCEaseIn *easeInAction = CCEaseIn::create(scaleSmallAction, 5.0f);
    CCFadeOut *fadeOutAction = CCFadeOut::create(0.1f);
    
    // 開始移動
    CCCallFunc *funcAction = CCCallFunc::create( this , callfunc_selector(GameBoardLayer::startMoveAnimation));
    CCCallFunc *funcSetTouchAction = CCCallFunc::create(this, callfunc_selector(GameBoardLayer::setCanTouchLayer));
    
    CCSequence *sequenceGoAction = CCSequence::create( easeOutAction , delayTime , easeInAction , funcAction , funcSetTouchAction , NULL );
    CCSequence *sequenceGoFadeInOutAction = CCSequence::create( fadeInAction , delayFadeInTime , fadeOutAction , NULL );
    
    goTTF->runAction(sequenceGoAction);
    goTTF->runAction(sequenceGoFadeInOutAction);
}

void GameBoardLayer::showBlockAnimation( BasicBlock *block ){
    
    // 設定位置
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    
    CCPoint blockPoint = this->getPointWithPosition( block->getBlockPoint() );
    block->setPosition( ccp(blockPoint.x, visibleSize.height + 50 ) );

    CCMoveTo *moveToAction = CCMoveTo::create(0.3f, blockPoint);
    CCEaseOut *easeOutAction = CCEaseOut::create(moveToAction, 5.0f);
    
    block->runAction(easeOutAction);
    
}

void GameBoardLayer::startMoveAnimation(){
    this->schedule(schedule_selector(GameBoardLayer::moveRandomBlocks), 0.6f* D_BlockGame_BlockMoveSpeed);
}

void GameBoardLayer::stopMoveAnimation(){
    this->unscheduleUpdate();
}

void GameBoardLayer::moveRandomBlocks(){
    
    if ( m_arrBlockArray->count() == 0 ) {
        this->stopMoveAnimation();
    }
    
    CCArray *array = CCArray::create();
    
    if ( m_uiBlockMaxMoveNumber > m_arrBlockArray->count() ) {
        m_uiBlockMaxMoveNumber = m_arrBlockArray->count();
    }
    
    for ( int i = 0 ; i < m_uiBlockMaxMoveNumber ; i++ ) {
        unsigned int randomNumber = arc4random()%(m_arrBlockArray->count());
        bool canAdd = true;
        for ( int i = 0 ; i < array->count() ; i++ ) {
            int number = ((CCString *)array->objectAtIndex(i))->intValue();
            if ( number == randomNumber  ) {
                canAdd = false;
            }
        }
        if ( canAdd ) {
            array->addObject( CCString::createWithFormat("%d" , randomNumber) );
        }
    }
    
    for ( int i = 0 ; i < array->count() ; i++ ) {
        BasicBlock *block = (BasicBlock *)m_arrBlockArray->objectAtIndex( ((CCString *)array->objectAtIndex(i))->intValue() );
        if ( block->checkIsMoving() ) {
            // 正在移動就不處理
        }
        else{
            BlockMoveManager *blockMoveManager = (BlockMoveManager *)this->getChildByTag(EnumGameBoardSceneTag_BlockMoveManager);
            int position = blockMoveManager->gpsGo(block->getBlockPoint());
            if ( position != -1 ) {
                block->goToPoint( position );
                blockMoveManager->synchronizeDic();
            }
        }
    }
}

void GameBoardLayer::releaseData(){
    
    m_arrBlockArray->removeAllObjects();
    m_arrBlockArray->release();
    m_arrBlockArray = NULL;
    
}

void GameBoardLayer::setCanTouchLayer(bool canTouch){
    this->setTouchEnabled( !m_bCanTouch );
}

// Touch 事件
void GameBoardLayer::ccTouchesEnded( cocos2d::CCSet *pTouches , cocos2d::CCEvent *pEvent ){
    // 只做這個
    CCTouch *_touch = (CCTouch *)pTouches->anyObject();
    
    CCPoint _location = _touch->getLocation();
    
    CCPoint _trueLocation = ccp(_location.x - this->getPositionX(), _location.y - this->getPositionY());
    
    for ( int i = 0 ; i < this->m_arrBlockArray->count() ; i++ ) {
        BasicBlock *block = (BasicBlock *)this->m_arrBlockArray->objectAtIndex(i);
        CCRect rect = CCRectMake(block->getPositionX() - block->getContentSize().width*0.5,
                                 block->getPositionY() - block->getContentSize().height*0.5,
                                 block->getContentSize().width,
                                 block->getContentSize().height);
        if ( rect.containsPoint(_trueLocation) ) {
            
            if ( m_uiRecentTargetNumber == block->getBlockNumber() ) {
                // 正確按到
#ifdef D_Dev_Ver
                CCLOG(" (O) 按到 %d !! （正確）" , m_uiRecentTargetNumber);
#endif
                // 消除 block
                block->disappearBlock( true , this , callfuncN_selector(GameBoardLayer::removeTouchBlock));
                this->setTargetNumber( CCString::createWithFormat("%d" , m_uiRecentTargetNumber+1) );
                
            }
            else{
                // 錯誤！
#ifdef D_Dev_Ver
                CCLOG(" (X) 按到 %d !! （錯誤）" , block->getBlockNumber());
#endif
                // 懲罰
            }
            
            break;
        }
    }

}

void GameBoardLayer::ccTouchesCancelled( cocos2d::CCSet *pTouches , cocos2d::CCEvent *pEvent ){
    
}

void GameBoardLayer::addNewBlock(){
    
}

void GameBoardLayer::removeBlock( BasicBlock *removeBlock ){
    m_arrBlockArray->removeObject( removeBlock );
    BlockMoveManager *blockMoveManager = (BlockMoveManager *)this->getChildByTag(EnumGameBoardSceneTag_BlockMoveManager);
    blockMoveManager->removeBlock(removeBlock);
}

void GameBoardLayer::removeTouchBlock( CCObject *object ){
    
    // 真正移除邏輯 block
    this->removeBlock((BasicBlock *)object);
    
    // 確認是否結束遊戲？
    if ( m_uiBlockMaxNumber > m_uiBlockMaxMoveNumber ) {
        // 結束遊戲
    }
    else if( 0 ){
        // 三次錯誤後失敗！
    }
}

void GameBoardLayer::remindPlayer(){
    
    // FIXIT: 這裡只是寫測試案例而已，請修正
    BasicBlock *block = (BasicBlock *)m_arrBlockArray->objectAtIndex(0);
    block->setZOrder(EnumGameBoardSceneTag_BlockTop);
    block->remindPlayer();
}

void GameBoardLayer::stopRemondPlayer(){
    
    // FIXIT: 這裡只是寫測試案例而已，請修正
    BasicBlock *block = (BasicBlock *)m_arrBlockArray->objectAtIndex(0);
    block->setZOrder(EnumGameBoardSceneTag_Block);
    block->stopRemindPlayer();
}




