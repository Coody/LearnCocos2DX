//
//  PokerManager.h
//  Test01
//
//  Created by CoodyChou on 2016/9/21.
//
//

#ifndef PokerManager_h
#define PokerManager_h

#include "cocos2d.h"

#include "PokerDefine.h"

class PokerManager : public cocos2d::CCNode
{
public:
    
    virtual bool init();
    CREATE_FUNC(PokerManager);
    
    // 得到一副新的撲克牌
    void initialNewCards();
    void shuffleCards();
    
    cocos2d::CCArray *getCards(unsigned int iCount);
    
#ifdef D_Test
    void flipCards(bool bOpne);
#endif
    
private:
    
    cocos2d::CCArray *cardArray;

#ifdef D_Test
    cocos2d::CCArray *onHandArray;
#endif
    
    // 查詢用
    EnumPokerFlowerColor getFlowerColor(unsigned int uNumber);
    EnumPokerNumber getNumber(unsigned int uNumber);
    
    // 取得真正的卡片圖片名稱
    const char *getCardPic(unsigned int uNumber);
    
};

#endif /* PokerManager_h */
