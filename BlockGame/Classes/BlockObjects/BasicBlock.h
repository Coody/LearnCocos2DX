//
//  BasicBlock.h
//  BlockGame
//
//  Created by Coody on 2016/10/3.
//
//

#ifndef BasicBlock_h
#define BasicBlock_h

#include "cocos2d.h"

// for Constant
#include "BlockGameConstant.h"

typedef enum{
    EnumBasicBlockTag_Background = 10,
    EnumBasicBlockTag_NumberLabel = 50
}EnumBasicBlockTag;

typedef enum{
    EnumBasicBlockActionTag_RemindAction = 501
}EnumBasicBlockActionTag;

class BasicBlock : public cocos2d::CCNode{
    
public:
    
    virtual bool initWithType( EnumBasicBlockType type , unsigned int blockNumber );
    
    static BasicBlock *create( EnumBasicBlockType type , unsigned int blockNumber ){
        BasicBlock *pRet = new BasicBlock();
        if ( pRet && pRet->initWithType( type , blockNumber ) ) {
            pRet->autorelease();
            return pRet;
        }
        else{
            delete pRet;
            pRet = NULL;
            return NULL;
        }
    }
    
    void setPointWithPosition( unsigned int targetPosition );
    unsigned int getBlockPoint();
    
    // 走到某點（上下左右四種而已）
    void goToPoint( unsigned int targetPoint );
    
    void stopMove();
    
    void appearTo( unsigned int targetPosition );
    
    // 回呼消失
    void disappearBlock(bool isSuccess ,
                        cocos2d::CCObject *targetObj ,
                        cocos2d::SEL_CallFuncN selDisappearDone );
    
    void changeBlockNumber( unsigned int newBlockNumber );
    
    unsigned int getBlockNumber();
    
    bool checkIsMoving();
    
    // 設定、取得 touch
    void setBlockTouch( bool canTouch );
    bool getBlockTouch();
    
    // 提醒新手
    void remindPlayer();
    void stopRemindPlayer();
    
    void changeBlockBGColor( float duration, GLshort deltaRed, GLshort deltaGreen, GLshort deltaBlue );
    
private:
    // 改變 block 數字的顏色
    void changeBlockColor( float duration, GLshort deltaRed, GLshort deltaGreen, GLshort deltaBlue );
    
    // 取得實際點位置
    cocos2d::CCPoint getPointWithPosition( unsigned int position );
    
    // 往上走
    void goUp();
    // 往下走
    void goDown();
    // 往左走
    void goLeft();
    //往右走
    void goRight();
    
    // 設定目前是否還在走動？
    void setNotMoving();
    
#pragma mark - Property
    bool m_bIsMoving;
    bool m_bCanTouch;
    
    EnumBasicBlockType m_enumBlockType;
    unsigned int m_iBlockNumber;
    unsigned int m_iBlockPosition;
};

#endif /* BasicBlock_h */
