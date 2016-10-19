//
//  ActionTools.cpp
//  BlockGame
//
//  Created by Chou Coody on 2016/10/1.
//
//

#include "ActionTools.h"

USING_NS_CC;

#pragma mark - Public
CCSequence *ActionTools::getHeartBitAnimation()
{
    
    CCScaleTo *scaleALittleBig = CCScaleTo::create( 0.05 , 1.2f * D_BlockGame_ActionTools_HeartBeatSpeed );
    CCEaseIn *easeInAction = CCEaseIn::create( scaleALittleBig , 0.5f * D_BlockGame_ActionTools_HeartBeatSpeed );
    CCScaleTo *scaleALittleSmall = CCScaleTo::create( 0.05 , 1.0f * D_BlockGame_ActionTools_HeartBeatSpeed );
    CCEaseOut *easeOutAction = CCEaseOut::create( scaleALittleSmall , 0.5f * D_BlockGame_ActionTools_HeartBeatSpeed );
    CCDelayTime *delayALittleTime = CCDelayTime::create( 0.5f * D_BlockGame_ActionTools_HeartBeatSpeed );
    CCSequence *sequenceHeartBit = CCSequence::create( easeInAction , easeOutAction , delayALittleTime , NULL );
    
    return sequenceHeartBit;
}

CCSpawn *ActionTools::getShowAnimation(cocos2d::CCObject *targetObj,
                                       cocos2d::SEL_CallFunc selResponseBlockDone)
{
    return ActionTools::getShowAnimation(0.3f,
                                         0.3f,
                                         1.1f,
                                         0.1f,
                                         targetObj,
                                         selResponseBlockDone);
}

/**
 *  顯示出場動畫的 Action（由正常大小 -> 變大 -> 變無 ）
 *
 */
CCSpawn *ActionTools::getHideAnimation(cocos2d::CCObject *targetObj,
                                       cocos2d::SEL_CallFunc selResponseBlockDone)
{
    return NULL;
}

CCSequence *ActionTools::getMoveInRightToLeftAnimation( float delayTime )
{
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    return ActionTools::getMoveInRightToLeftAnimation(delayTime * D_BlockGame_ActionTools_HeartBeatSpeed,
                                                      ccp(visibleSize.width*-0.5, 0 ),
                                                      0.5f * D_BlockGame_ActionTools_HeartBeatSpeed,
                                                      0.3f * D_BlockGame_ActionTools_HeartBeatSpeed);
}

CCSequence *ActionTools::getMoveOutLeftToRightAnimation( float delayTime )
{
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    return ActionTools::getMoveOutLeftToRightAnimation(delayTime * D_BlockGame_ActionTools_HeartBeatSpeed,
                                                       ccp( visibleSize.width*0.5 , 0 ),
                                                       0.35f * D_BlockGame_ActionTools_HeartBeatSpeed,
                                                       0.15f * D_BlockGame_ActionTools_HeartBeatSpeed);
}

CCSpawn *ActionTools::getShowAnimation(float delayTime,
                                          float scaleBigTime,
                                          float bigRate,
                                          float scaleSmallTime,
                                          cocos2d::CCObject *targetObj,
                                          cocos2d::SEL_CallFunc selResponseBlockDone)
{
    return ActionTools::getShowAnimation(delayTime,
                                         scaleBigTime,
                                         bigRate,
                                         scaleSmallTime,
                                         1.0f,
                                         0.3f,
                                         targetObj,
                                         selResponseBlockDone);
}

CCSpawn *ActionTools::getHideAnimation(float delayTime,
                                          float scaleBigTime,
                                          float bigRate,
                                          float scaleSmallTime,
                                          cocos2d::CCObject *targetObj,
                                          cocos2d::SEL_CallFunc selResponseBlockDone)
{
    return NULL;
}

#pragma mark - Private
CCSpawn *ActionTools::getShowAnimation(float delayTime,
                                       float scaleBigTime, 
                                       float bigRate,
                                       float scaleSmallTime,
                                       float smallRate,
                                       float fadeInTime,
                                       cocos2d::CCObject *targetObj,
                                       cocos2d::SEL_CallFunc selResponseBlockDone)
{
    CCDelayTime *delayTimeAction = CCDelayTime::create(delayTime);
    CCScaleTo *scaleBigAction = CCScaleTo::create( scaleBigTime , bigRate );
    CCEaseOut *easeAction = CCEaseOut::create( scaleBigAction , 0.5f );
    
    CCScaleTo *scaleSmallAction = CCScaleTo::create( scaleSmallTime , smallRate );
    CCEaseInOut *easeSmallAction = CCEaseInOut::create(scaleSmallAction, 0.5f);
    
    // 加入 scale Action
    CCSequence *sequenceAction;
    CCCallFunc *callBackAction;
    CCArray *scaleActionArray = CCArray::create();
    CCArray *fadeActionArray = CCArray::create();
    if ( delayTime > 0 ) {
        fadeActionArray->addObject( delayTimeAction );
        scaleActionArray->addObject( delayTimeAction );
    }
    scaleActionArray->addObject( easeAction );
    scaleActionArray->addObject( easeSmallAction );
    if ( targetObj != NULL && selResponseBlockDone != NULL ) {
        callBackAction = CCCallFunc::create( targetObj , selResponseBlockDone );
        scaleActionArray->addObject( callBackAction );
    }
    sequenceAction = CCSequence::create(scaleActionArray);
    
    // 加入 fade Action
    CCSpawn *spawn;
    CCFadeIn *fadeInAction;
    CCSequence *fadeSequenceAction;
    if ( fadeInTime > 0 ) {
        fadeInAction = CCFadeIn::create(fadeInTime);
        fadeActionArray->addObject( fadeInAction );
        spawn = CCSpawn::create( sequenceAction , fadeSequenceAction , NULL );
    }
    else{
        spawn = CCSpawn::create( sequenceAction , NULL );
    }
    
    return spawn;
}

CCSequence *ActionTools::getHideAnimation(float scaleBigTime,
                                          float bigRate,
                                          float scaleSmallTime,
                                          float smallRate)
{
    CCScaleBy *scaleBigAction = CCScaleBy::create(0.3f, 1.5f);
    CCEaseIn *easeBigAction = CCEaseIn::create(scaleBigAction, 0.7f);
    CCDelayTime *delay = CCDelayTime::create(0.15f);
    CCScaleBy *scaleSmallAction = CCScaleBy::create(0.15f, 0.0f);
    CCEaseOut *easeSmallAction = CCEaseOut::create(scaleSmallAction, 0.7f);
    
//    CCCallFunc *funcAction = CCCallFunc::create(this, callfunc_selector(StartMenuLayer::changeScene));
    
    CCSequence *sequenceAction = CCSequence::create( easeBigAction , delay , easeSmallAction  , NULL);
    return sequenceAction;
}

CCSequence *ActionTools::getMoveInRightToLeftAnimation(float delayTime,
                                                    cocos2d::CCPoint endPoint,
                                                    float moveInTime,
                                                    float fadeInTime)
{
    CCMoveBy *moveToAction = CCMoveBy::create(moveInTime, endPoint );
    CCEaseOut *easeAction = CCEaseOut::create(moveToAction, 1.0f);
    CCFadeIn *fadeInAction = CCFadeIn::create(fadeInTime);
    CCDelayTime *delay = CCDelayTime::create(0.4f);
    
    CCSpawn *spawn = CCSpawn::create(easeAction , fadeInAction , NULL );
    CCSequence *sequence = CCSequence::create( delay , spawn , NULL );
    return sequence;
}

CCSequence *ActionTools::getMoveOutLeftToRightAnimation(float delayTime,
                                                        cocos2d::CCPoint endPoint,
                                                        float moveOutTime,
                                                        float fadeOutTime)
{
    CCMoveBy *moveToAction = CCMoveBy::create(moveOutTime,
                                              endPoint);
    CCEaseIn *easeAction = CCEaseIn::create(moveToAction, 1.0f);
    CCFadeOut *fadeOutAction = CCFadeOut::create(fadeOutTime);
    
    CCDelayTime *delay = CCDelayTime::create( delayTime );
    
    CCSpawn *spawn = CCSpawn::create(easeAction , fadeOutAction , NULL );
    CCSequence *sequence = CCSequence::create( delay , spawn , NULL );
    return sequence;
}


