# Learn cocos2D-X

練習用，筆記可放這。
```
注意！這個筆記是為了自己好理解的想法而做，不是給他人的教學教材！
```

# 0. 建置專案（可以做成 shell script 來使用）

* python create_project.py -project $ProjectName -package $ProjectBundleIdentifier -language $ProjectLanguage
  * __$ProjectName__ 為專案名稱，如： OoxxGame。
  * __$ProjectBundleIdentifier__ 為專案的 Bundle Identifier ，在 Android 上則為 Java 專案的資料夾結構。
  * __$ProjectLanguage__ 為使用的語言，有 lua , C++ , ooxx ，可未來熟悉整個框架後如果
，設定自己的專案語言可以來建置 cocos2d 的專案

# 1. C++ 中的類別 .h 可視為 struct 的一種，因此：
```
class Ooxx : public cocos2d::CCLayer{  <-- 注意要有 public
    // Data members
};  <-- 要有分號
```
