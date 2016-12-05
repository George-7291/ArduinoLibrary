#ifndef __TA7291P__
#define __TA7291P__

#include <Arduino.h>
#include <DriverIcForMotor.h>

/**
 * ドライバIC-TA7291P-を扱うためのクラス
 * @author George-7291
 */
class Ta7291p : public DriverIcForMotor{
	public:
		/**
	 	 * コンストラクタ
	 	 * ICと繋いだ、Arduino側のピン番号を指定する
	 	 * @param pin4	ICの4番ピンに接続するArduinoのピン番号
	 	 *							このピンはPWM出力に対応したピンでないと動作しない
	 	 *
	 	 * @param pin5	ICの5番ピンに接続するArduinoのピン番号
	 	 *							通常のデジタルピン
	 	 *
	 	 * @param pin6	ICの6番ピンに接続するArduinoのピン番号
	 	 *							通常のデジタルピン
	 	 */
		Ta7291p(int pin4, int pin5, int pin6);
		~Ta7291p(void);
	
		/**
	 	 * モータを動かす
	 	 * @param pwm	動かす速度（-255 ~ 255)
	 	 * @Override <!-- from DriverIcForMotor -->
	 	 */
		void commitPwm(int pwm);
	
		/**
	 	 * ブレーキモードにする
		 * @param break	true  : ブレーキモード<br>
	 	 * 							false : フロートモード
	 	 * @Override <!-- from DriverIcForMotor -->
	 	 */
		void applyBrake(bool brake);
	
		/**
	 	 * 現在の速度を返す
	 	 * @return	現在の速度
	 	 * @Override <!-- from DriverIcForMotor -->
	 	 */
		inline int  fetchPwm(void);
	
		/**
	 	 * 現在ブレーキモードかどうかを返す
	 	 * @return	ブレーキモード : true<br>
		 *					フロートモード : false
	 	 * @Override <!-- from DriverIcForMotor -->
		 */
		inline bool isBraked(void);
		
	private:
		Ta7291p(void);
		int pin4;
		int pin5;
		int pin6;
		int pwm;
		bool brake;
};

#endif