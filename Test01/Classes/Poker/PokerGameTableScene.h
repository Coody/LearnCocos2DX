//
//  PokerGameTableScene.h
//  Test01
//
//  Created by Coody on 2016/9/20.
//
//

#ifndef PokerGameTableScene_h
#define PokerGameTableScene_h

#include "cocos2d.h"

// for Constant
#include "PokerDefine.h"

class PokerGameTableLayer : public cocos2d::CCLayerColor
{
public:
    virtual bool init();
    
    static cocos2d::CCScene *scene();
    
    CREATE_FUNC(PokerGameTableLayer);
    
private:
    
    cocos2d::CCArray *cardArray;
    
    void flipCard( bool bIsNeedOpen );
    void changeCard( unsigned int uCount);
#ifdef D_Test_Sequence
    void runFlipCardAction(CCNode *sender);
#endif
};


#endif /* PokerGameTableScene_h */
