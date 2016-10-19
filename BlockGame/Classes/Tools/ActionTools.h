//
//  ActionTools.hpp
//  BlockGame
//
//  Created by Chou Coody on 2016/10/1.
//
//

#ifndef ActionTools_h
#define ActionTools_h

#include "cocos2d.h"

#define D_BlockGame_ActionTools_HeartBeatSpeed (1.0f)

class ActionTools : public cocos2d::CCNode{
public:
    
#pragma mark - 心跳動作（ repeat forever ）
    /**
     *  心跳的 Action
     */
    static cocos2d::CCSequence *getHeartBitAnimation();
    
#pragma mark - Title 動畫
    /**
     *  顯示進場動畫的 Action（由無 -> 變大 -> 變正常大小 ）
     *
     */
    static cocos2d::CCSpawn *getShowAnimation(cocos2d::CCObject *targetObj,
                                                 cocos2d::SEL_CallFunc selResponseBlockDone);
    
    /**
     *  顯示出場動畫的 Action（由正常大小 -> 變大 -> 變無 ）
     *
     */
    static cocos2d::CCSpawn *getHideAnimation(cocos2d::CCObject *targetObj,
                                                 cocos2d::SEL_CallFunc selResponseBlockDone);
    
    // TODO: 要加入結束動畫後，可以 call back 的方法
    /**
     *  顯示進場動畫的 Action（由無 -> 變大 -> 變正常大小 ）
     *
     *  @param delayTime      延遲動作時間
     *  @param scaleBigTime   變大的時間
     *  @param bigRate        變大的倍率
     *  @param scaleSmallTime 變小的時間
     *  @param targetObj      回呼對象
     *  @param selResponseBlockDone 回呼函式
     */
    static cocos2d::CCSpawn *getShowAnimation(float delayTime,
                                                 float scaleBigTime,
                                                 float bigRate,
                                                 float scaleSmallTime,
                                                 cocos2d::CCObject *targetObj,
                                                 cocos2d::SEL_CallFunc selResponseBlockDone);
    
    /**
     *  顯示出場動畫的 Action（由正常大小 -> 變大 -> 變無 ）
     *
     *  @param delayTime      延遲動作時間
     *  @param scaleBigTime   變大的時間
     *  @param bigRate        變大的倍率
     *  @param scaleSmallTime 變小的時間
     *  @param targetObj      回呼對象
     *  @param selResponseBlockDone 回呼函式
     */
    static cocos2d::CCSpawn *getHideAnimation(float delayTime,
                                                 float scaleBigTime,
                                                 float bigRate,
                                                 float scaleSmallTime,
                                                 cocos2d::CCObject *targetObj,
                                                 cocos2d::SEL_CallFunc selResponseBlockDone);
    
#pragma mark - Menu 動畫（由右而左出現動畫）
    /**
     *  由右而左出現的選單動畫
     *
     *  @param delayTime 可設定延遲動畫時間，讓選單可以達成依序出現功能
     */
    static cocos2d::CCSequence *getMoveInRightToLeftAnimation( float delayTime );
    
    /**
     *  由左而右移出的選單動畫
     *
     *  @param delayTime 可設定延遲動畫時間，讓選單可以達成依序消失功能
     */
    static cocos2d::CCSequence *getMoveOutLeftToRightAnimation( float delayTime );
    
    
private:
#pragma mark - Private 的 Title 動畫
    /**
     *  顯示進場動畫的 Action（由無 -> 變大 -> 變正常大小 ）
     *
     *  @param scaleBigTime   變大的時間
     *  @param bigRate        變大的倍率
     *  @param scaleSmallTime 變小的時間
     *  @param smallRate      變小的倍率
     */
    static cocos2d::CCSpawn *getShowAnimation(float delayTime,
                                              float scaleBigTime, 
                                              float bigRate,
                                              float scaleSmallTime,
                                              float smallRate,
                                              float fadeInTime,
                                              cocos2d::CCObject *targetObj,
                                              cocos2d::SEL_CallFunc selResponseBlockDone);
    
    /**
     *  顯示出場動畫的 Action（由正常大小 -> 變大 -> 變無 ）
     *
     *  @param scaleBigTime   變大的時間
     *  @param bigRate        變大的倍率
     *  @param scaleSmallTime 變小的時間
     *  @param smallRate      變小的倍率
     */
    static cocos2d::CCSequence *getHideAnimation(float scaleBigTime,
                                                 float bigRate,
                                                 float scaleSmallTime,
                                                 float smallRate);
    
#pragma mark - Private 的 Menu 動畫
    static cocos2d::CCSequence *getMoveInRightToLeftAnimation(float delayTime,
                                                              cocos2d::CCPoint endPoint,
                                                              float moveInTime,
                                                              float fadeInTime);
    
    static cocos2d::CCSequence *getMoveOutLeftToRightAnimation(float delayTime,
                                                               cocos2d::CCPoint endPoint,
                                                               float moveOutTime,
                                                               float fadeOutTime);
    
};

#endif /* ActionTools_h */
