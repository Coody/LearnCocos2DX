//
//  PokerDefine.h
//  Test01
//
//  Created by Coody on 2016/9/20.
//
//

#ifndef PokerDefine_h
#define PokerDefine_h

/**
 撲克牌號碼由 0~51 為所有花色 + 52 為鬼牌
 */

/**
 花色
 */
typedef enum{
    EnumPokerFlowerColor_NotSet = -1,
    
    EnumPokerFlowerColor_Clubs = 0,
    EnumPokerFlowerColor_Diamonds = 1,
    EnumPokerFlowerColor_Hearts = 2,
    EnumPokerFlowerColor_Spades = 3,
    
    EnumPokerNumberColor_Ghost = 4
}EnumPokerFlowerColor;

/**
 牌數
 */
typedef enum{
    EnumPokerNumber_NotSet = -1,
    
    EnumPokerNumber_1 = 0 ,
    EnumPokerNumber_2 = 1 ,
    EnumPokerNumber_3 = 2 ,
    EnumPokerNumber_4 = 3 ,
    EnumPokerNumber_5 = 4 ,
    EnumPokerNumber_6 = 5 ,
    EnumPokerNumber_7 = 6 ,
    EnumPokerNumber_8 = 7 ,
    EnumPokerNumber_9 = 8 ,
    EnumPokerNumber_10 = 9 ,
    EnumPokerNumber_Jack = 10 ,
    EnumPokerNumber_Queen = 11 ,
    EnumPokerNumber_King = 12 ,
    
    EnumPokerNumber_Ghost = 0,
}EnumPokerNumber;

/**
 動畫的速度
 */
#define D_Animation_Speed (0.6f)

#endif /* PokerDefine_h */
