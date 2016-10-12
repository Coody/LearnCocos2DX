//
//  GameBoardScene.h
//  BlockGame
//
//  Created by Chou Coody on 2016/10/3.
//
//

#ifndef GameBoardScene_h
#define GameBoardScene_h

#include "cocos2d.h"

// for Constant
#include "BlockGameConstant.h"

// for Object
#include "BasicBlock.h"

typedef enum{
    EnumGameBoardSceneTag_TopBar = 10,
    EnumGameBoardSceneTag_TopBar_TargetTitle = 20,
    EnumGameBoardSceneTag_TopBar_TimeTitle = 40,
    EnumGameBoardSceneTag_TopBar_ScoreTitle = 50,
    EnumGameBoardSceneTag_TopBar_SkillTitle = 60,
    EnumGameBoardSceneTag_TopBar_SkillOne = 70,
    EnumGameBoardSceneTag_TopBar_SkillTwo = 80,
    EnumGameBoardSceneTag_TopBar_SkillThree = 90,
    EnumGameBoardSceneTag_Block = 500,
    EnumGameBoardSceneTag_BlockTop = 505,
    EnumGameBoardSceneTag_TopBar_TargetNumber = 550,
    EnumGameBoardSceneTag_Ready = 600,
    EnumGameBoardSceneTag_Go = 610,
    EnumGameBoardSceneTag_BlockMoveManager = 1000,
    EnumGameBoardSceneTag_ClockTool_BasicClock = 1010,
    EnumGameBoardSceneTag_ClockTool_PlayerHelper = 1020,
    EnumGameBoardSceneTag_EndGameLayer = 2000
}EnumGameBoardSceneTag;

typedef enum{
    EnumGameBoardSceneActionTag_RemindPlayer = 100
}EnumGameBoardSceneActionTag;

typedef enum{
    EnumGameBoardState_Wait = 1,
    EnumGameBoardState_Playing = 2,
    EnumGameBoardState_Win = 3,
    EnumGameBoardState_Lose = 4
}EnumGameBoardState;

class GameBoardLayer : public cocos2d::CCLayerColor{

public:
    
    virtual bool init( EnumGameBoard_Level level );
    
    static cocos2d::CCScene *scene( EnumGameBoard_Level level );
    
    static GameBoardLayer *create( EnumGameBoard_Level level ){
        GameBoardLayer *pRet = new GameBoardLayer();
        if ( pRet && pRet->init( level ) ) {
            pRet->autorelease();
            return pRet;
        }
        else{
            delete pRet;
            pRet = NULL;
            return NULL;
        }
    }
    
    void startSceneAnimation();
    void initialBlocks( unsigned int count );
    
private:
    
    // 初始話、建立 blocks
    void setGameLevel( EnumGameBoard_Level newLevel );
    void createBlocks();
    
    //========= 動畫 ==========//
    /**
     *  只呼叫一次的 Target Title 動畫
     */
    void showRecentTargetTitle();
    void initialBlockAnimation();
    void setTargetNumber( cocos2d::CCString *text );
    void changeTargetNumberString( CCObject *object );
    void playTargetNumberAppearAnimation();
    void playClockNumberAppearAnimation();
    void playReadyAnimation();
    void playGoAnimation();
    void playTimeAnimation();
    
    // 設定遊戲狀態
    void setGameState( EnumGameBoardState gameState);
    
    // 取得實際點位置
    cocos2d::CCPoint getPointWithPosition( unsigned int position );
    void showBlockAnimation( BasicBlock *block );
    
    // 開始移動
    void startMoveAnimation();
    void stopMoveAnimation();
    void moveRandomBlocks();
    
    // 時間處理
    void startTimer();
    void stopTimer();
    
    // free memory
    void releaseData();
    
    // touch 事件
    void setCanTouchLayer(bool canTouch);
    virtual void ccTouchesEnded( cocos2d::CCSet *pTouches , cocos2d::CCEvent *pEvent );
    virtual void ccTouchesCancelled( cocos2d::CCSet *pTouches , cocos2d::CCEvent *pEvent );
    
    // 新增、移除 block
    void addNewBlock();
    void removeBlock( BasicBlock *removeBlock );
    void removeTouchBlock( CCObject *object );
    
    // 提醒目前的 block
    void remindRecentNumber();
    void remindTargets( cocos2d::CCArray *targetNumbers );
    void stopRemindRecentNumber();
    void stopRemindTargets( cocos2d::CCArray *targetNumbers );
    
    // 聲音
    void playFallDownSound();
    
#pragma mark - Property
    // Properties
    bool m_bCanTouch;
    EnumGameBoard_Level m_enumRecentLevel;
    EnumGameBoardState m_enumGameState;
    unsigned int m_uiBlockMaxNumber;
    unsigned int m_uiBlockMaxMoveNumber;
    unsigned int m_uiRecentTargetNumber;// 目前目標的 Number
    cocos2d::CCArray *m_arrBlockArray;
    cocos2d::CCDictionary *m_dicGameBoardDic;
};

#endif /* GameBoardScene_h */
