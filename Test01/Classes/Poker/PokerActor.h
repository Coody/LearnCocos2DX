//
//  PokerActor.h
//  Test01
//
//  Created by Coody on 2016/9/20.
//
//

#ifndef PokerActor_h
#define PokerActor_h

#include "cocos2d.h"

// for define
#include "PokerDefine.h"

class PokerActor : public cocos2d::CCNode
{
public:
    
    virtual bool init();
    CREATE_FUNC(PokerActor);
    
    // 設定 Poker 的花色與數字
    void setPokerNumber( unsigned int uNumber );
    void setFlowerColor( EnumPokerFlowerColor enumFlowerColor );
    void setNumber(EnumPokerNumber enumPokerNumber );
    
    // 設定 Poker 的圖片（可以使用 .plist 以及 Texture ）
    void setPokerCardImage( const char *sBackString , const char *sFrontString );
    
    // 取得花色與數字
    EnumPokerFlowerColor getPokerFlowerColor();
    EnumPokerNumber getPokerNumber();
    
    // 是否為打開狀態？
    bool isOpen();
    
    // 設定打開 or 關閉
    void filp( bool bOpen);
    
private:
    
    /** 卡片狀態（開/關），預設關 */
    bool m_bIsFlip;
    /** 卡片實際的數值（0~52（含鬼牌）） */
    unsigned int m_uCardNumber;
    /** 卡片花色 */
    EnumPokerFlowerColor enumColor;
    /** 卡片數值 */
    EnumPokerNumber enumNumber;
    
    
    // 內部檢測動畫停止了嗎？
    bool m_bIsAnimating;
    void endAnimating();
};

#endif /* PokerActor_h */
