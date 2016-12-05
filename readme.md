# Arduinoライブラリ

## DriverIcForMotor
このクラスは、モータを扱うためのクラスに実装するインターフェース。モータを扱うためのメソッドが宣言されている。  

#### 公開メソッド
|メソッド|説明|
|:----:|:---|
|`virtual void commitPwm(int pwm)`|モータを回すためのメソッド。引数`pwm`に回したい速さの値を入れる。|
|`virtual void applyBrake(bool brake)`|モータのブレーキの設定をする。`brake`が`true`でブレーキモード、`false`でフロートモード。|
|`virtual int fetchPwm(void)`|現在セットされているPWMの値を取得する。|
|`virtual bool isBraked(void)`|現在のブレーキの設定を取得する。|

これらのメソッドは全て純粋仮想関数なので、実装する場合は必ずオーバーライドしてください。

## Ta7291p
|必要なクラス|
|:-:|
|**DriverIcForMotor**|
このクラスは、ドライバIC**TA7291p**を扱うためのクラス。DriverIcForMotorインターフェースを実装している。


#### 公開メソッド
|メソッド|説明|
|:----:|:---|
|`Ta7291p(int pin4, int pin5, int pin6)`|コンストラクタ。それぞれICのpin4,pin5,pin6に接続しているArduino側のピン番号を指定してインスタンスを作る。|
|`void commitPwm(int pwm)`|モータを回すためのメソッド。引数`pwm`に回したい速さの値を入れる。（-255 ~ 255）|
|`void applyBrake(bool brake)`|モータのブレーキの設定をする。`brake`が`true`でブレーキモード、`false`でフロートモード。|
|`int fetchPwm(void)`|現在セットされているPWMの値を取得する。|
|`bool isBraked(void)`|現在のブレーキの設定を取得する。|

#### サンプルコード
~~~c++
#include <DriverIcForMotor.h>
#include <Ta7291p.h>

int analog_out = 9;		//アナログ出力に対応しているPin
int digital_out1 = 8;	//デジタルPin
int digital_out2 = 7;	//デジタルPin

DriverIcForMotor* tmp = new Ta7291p(analog_out, digital_out1, digital_out2);

void setup() {
}

void loop() {
  tmp->commitPwm(255); //モータを正回転
  delay(1000);
  tmp->commitPwm(-255); //モータを逆回転
  delay(1000);
}
~~~





















