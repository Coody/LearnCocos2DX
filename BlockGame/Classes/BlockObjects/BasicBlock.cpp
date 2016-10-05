//
//  BasicBlock.cpp
//  BlockGame
//
//  Created by Coody on 2016/10/3.
//
//

#include "BasicBlock.h"

// for Constant
#include "BlockGameConstant.h"

USING_NS_CC;

#pragma mark - Public
bool BasicBlock::initWithType(EnumBasicBlockType type, unsigned int blockNumber){
    
    if ( CCNode::create() ) {
        
        this->setAnchorPoint(ccp(0, 0));
        m_bIsMoving = false;
        m_bCanTouch = true;
        m_enumBlockType = type;
        m_iBlockNumber = blockNumber;
        m_iBlockPosition = blockNumber;
        
        CCSprite *bgsprite = CCSprite::create("block.png");
        bgsprite->setAnchorPoint(ccp(0.5, 0.5));
        this->addChild(bgsprite , EnumBasicBlockTag_Background , EnumBasicBlockTag_Background);
        
        CCLabelTTF *numberLabel = CCLabelTTF::create(CCString::createWithFormat("%d" , blockNumber)->getCString(),
                                                     D_BlockGame_FontName2,
                                                     60);
        numberLabel->setColor(ccBLACK);
        numberLabel->setAnchorPoint(ccp(0.5, 0.5));
        numberLabel->setPosition(ccp(-3, -7));
        this->addChild( numberLabel , EnumBasicBlockTag_NumberLabel , EnumBasicBlockTag_NumberLabel);
        
        this->setPosition(bgsprite->getPosition());
        
        if ( blockNumber % 5 == 0 ) {
            
            this->changeBlockColor(0.7f, 250, 74, 79);
        }
        
        this->setContentSize( CCSizeMake(100, 100) );
        
        return true;
    }
    
    return false;
}

unsigned int BasicBlock::getBlockNumber(){
    return m_iBlockNumber;
}

bool BasicBlock::checkIsMoving(){
    return m_bIsMoving;
}

void BasicBlock::setPointWithPosition( unsigned int targetPosition ){
    m_iBlockPosition = targetPosition;
    this->setPosition( this->getPointWithPosition(targetPosition) );
}

unsigned int BasicBlock::getBlockPoint(){
    return m_iBlockPosition;
}

// 往上走
void BasicBlock::goToPoint(unsigned int targetPoint){
    if ( m_bIsMoving == false ) {
        m_bIsMoving = true;
        switch ( targetPoint - m_iBlockPosition ) {
            case 6:
            {
                // 上
                this->goUp();
            }
                break;
            case 1:
            {
                // 右
                this->goRight();
            }
                break;
            case -1:
            {
                // 左
                this->goLeft();
            }
                break;
            case -6:
            {
                // 下
                this->goDown();
            }
                break;
            default:
                break;
        }
        m_iBlockPosition = targetPoint;
    }
}

void BasicBlock::stopMove(){
    this->stopAllActions();
}

void BasicBlock::appearTo( unsigned int targetPosition ){
    
}

void BasicBlock::disappearBlock(bool isSuccess ,
                                cocos2d::CCObject *targetObj ,
                                cocos2d::SEL_CallFuncN selDisappearDone ){
    
    CCLabelTTF *numberLabel = (CCLabelTTF *)getChildByTag(EnumBasicBlockTag_NumberLabel);
    CCSprite *bgsprite = (CCSprite *)getChildByTag(EnumBasicBlockTag_Background);
    
    this->stopRemindPlayer();
    this->stopMove();
    
    m_bIsMoving = true;
    this->setBlockTouch( false );
    
    
    CCScaleTo *scaleSmall = CCScaleTo::create(0.5f * D_BlockGame_BlockMoveSpeed, 0.7f);
    CCEaseIn *easeInAction = CCEaseIn::create(scaleSmall, 5.0f);
    
    {
        CCFadeOut *fadeOutAction = CCFadeOut::create(0.35f * D_BlockGame_BlockMoveSpeed);
        CCEaseIn *easeFadeOutAction = CCEaseIn::create(fadeOutAction, 0.5f);
        numberLabel->runAction(easeFadeOutAction);
    }
    
    {
        CCFadeOut *fadeOutAction = CCFadeOut::create(0.35f * D_BlockGame_BlockMoveSpeed);
        CCEaseIn *easeFadeOutAction = CCEaseIn::create(fadeOutAction, 0.5f);
        bgsprite->runAction(easeFadeOutAction);
    }
    
    {
        CCFadeOut *fadeOutAction = CCFadeOut::create(0.35f * D_BlockGame_BlockMoveSpeed);
        CCEaseIn *easeFadeOutAction = CCEaseIn::create(fadeOutAction, 0.5f);
        this->runAction(easeFadeOutAction);
    }
    
    // 回呼函式
    if ( targetObj != NULL && selDisappearDone != NULL ) {
        CCCallFuncN *callFuncN = CCCallFuncN::create( targetObj , selDisappearDone ) ;
        CCDelayTime *delayFunc = CCDelayTime::create(0.5f);
        CCSequence *sequenceAction = CCSequence::create( easeInAction , delayFunc , callFuncN , NULL);
        this->runAction(sequenceAction);
    }
    else{
        this->runAction(easeInAction);
    }
    
}

void BasicBlock::setBlockTouch( bool canTouch ){
    m_bCanTouch = canTouch;
}

bool BasicBlock::getBlockTouch(){
    return m_bCanTouch;
}

void BasicBlock::remindPlayer(){
    CCScaleTo *scaleBig = CCScaleTo::create( 0.5f , 1.2f);
    CCEaseOut *easeOut = CCEaseOut::create(scaleBig, 1.0f);
    CCScaleTo *scaleSmall = CCScaleTo::create( 0.5f , 0.9f);
    CCEaseInOut *easeInOut = CCEaseInOut::create(scaleSmall, 1.0f);
    CCSequence *sequence = CCSequence::create( easeOut , easeInOut , NULL);
    CCRepeatForever *repeat = CCRepeatForever::create(sequence);
    repeat->setTag(EnumBasicBlockActionTag_RemindAction);
    this->runAction(repeat);
}

void BasicBlock::stopRemindPlayer(){
    this->stopActionByTag(EnumBasicBlockActionTag_RemindAction);
}

void changeBlockBGColor( float duration, GLshort deltaRed, GLshort deltaGreen, GLshort deltaBlue ){
    
}

void BasicBlock::changeBlockNumber( unsigned int newBlockNumber ){
    
}

void BasicBlock::setNotMoving(){
    m_bIsMoving = false;
}

#pragma mark - Private
void BasicBlock::changeBlockColor( float duration, GLshort deltaRed, GLshort deltaGreen, GLshort deltaBlue ){
    
    CCLabelTTF *numberLabel = (CCLabelTTF *)this->getChildByTag(EnumBasicBlockTag_NumberLabel);
    
    CCTintBy *tintRedBy = CCTintBy::create( duration , deltaRed , deltaGreen , deltaBlue );
    CCEaseOut *easeOut = CCEaseOut::create(tintRedBy, 5.0f);
    CCDelayTime *delay = CCDelayTime::create(0.5f);
    CCTintBy *tintOriginalBy = CCTintBy::create( duration , deltaRed*-1 , deltaGreen*-1 , deltaBlue*-1 );
    CCEaseIn *easeIn = CCEaseIn::create(tintOriginalBy, 5.0f);
    CCSequence *sequenct = CCSequence::create(easeOut , delay , easeIn , NULL);
    CCRepeatForever *repeat = CCRepeatForever::create(sequenct);
    numberLabel->runAction(repeat);
}

CCPoint BasicBlock::getPointWithPosition( unsigned int position ){
    CCPoint targetPoint = ccp( 70 + 50*(m_iBlockPosition%6) , 70 + 50*(int)(m_iBlockPosition/6) );
    return targetPoint;
}


// 往上走
void BasicBlock::goUp(){
    CCMoveBy *moveBy = CCMoveBy::create(0.55f * D_BlockGame_BlockMoveSpeed, ccp(0, 100));
    CCEaseInOut *easeAction = CCEaseInOut::create(moveBy, 10.0f);
    CCCallFunc *funcSetNotMovingAction = CCCallFunc::create( this , callfunc_selector(BasicBlock::setNotMoving));
    this->runAction(CCSequence::create( easeAction , funcSetNotMovingAction , NULL ));
}

// 往下走
void BasicBlock::goDown(){
    CCMoveBy *moveBy = CCMoveBy::create(0.55f * D_BlockGame_BlockMoveSpeed, ccp(0, -100));
    CCEaseInOut *easeAction = CCEaseInOut::create(moveBy, 10.0f);
    CCCallFunc *funcSetNotMovingAction = CCCallFunc::create( this , callfunc_selector(BasicBlock::setNotMoving));
    this->runAction(CCSequence::create( easeAction , funcSetNotMovingAction , NULL ));
}

// 往左走
void BasicBlock::goLeft(){
    CCMoveBy *moveBy = CCMoveBy::create(0.55f * D_BlockGame_BlockMoveSpeed, ccp(-100, 0));
    CCEaseInOut *easeAction = CCEaseInOut::create(moveBy, 10.0f);
    CCCallFunc *funcSetNotMovingAction = CCCallFunc::create( this , callfunc_selector(BasicBlock::setNotMoving));
    this->runAction(CCSequence::create( easeAction , funcSetNotMovingAction , NULL ));
}

//往右走
void BasicBlock::goRight(){
    CCMoveBy *moveBy = CCMoveBy::create(0.55f * D_BlockGame_BlockMoveSpeed, ccp(100,0));
    CCEaseInOut *easeAction = CCEaseInOut::create(moveBy, 10.0f);
    CCCallFunc *funcSetNotMovingAction = CCCallFunc::create( this , callfunc_selector(BasicBlock::setNotMoving));
    this->runAction(CCSequence::create( easeAction , funcSetNotMovingAction , NULL ));
}

