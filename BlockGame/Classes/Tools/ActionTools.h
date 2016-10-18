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
    
    /**
     *  心跳的 Action
     */
    static cocos2d::CCSequence *getHeartBitAnimation();
    
    /**
     *  顯示進場動畫的 Action（由無 -> 變大 -> 變正常大小 ）
     *
     *  @param scaleBigTime   變大的時間
     *  @param bigRate        變大的倍率
     *  @param scaleSmallTime 變小的時間
     */
    static cocos2d::CCSequence *getShowAnimation(float scaleBigTime,
                                                 float bigRate,
                                                 float scaleSmallTime);
    
    /**
     *  顯示出場動畫的 Action（由正常大小 -> 變大 -> 變無 ）
     *
     *  @param scaleBigTime   變大的時間
     *  @param bigRate        變大的倍率
     *  @param scaleSmallTime 變小的時間
     */
    static cocos2d::CCSequence *getHideAnimation(float scaleBigTime,
                                                 float bigRate,
                                                 float scaleSmallTime);
    
private:
    /**
     *  顯示進場動畫的 Action（由無 -> 變大 -> 變正常大小 ）
     *
     *  @param scaleBigTime   變大的時間
     *  @param bigRate        變大的倍率
     *  @param scaleSmallTime 變小的時間
     *  @param smallRate      變小的倍率
     */
    static cocos2d::CCSequence *getShowAnimation(float scaleBigTime,
                                                 float bigRate,
                                                 float scaleSmallTime,
                                                 float smallRate);
    
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
};

#endif /* ActionTools_h */
