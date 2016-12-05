#ifndef __DRIVER_IC_FOR_MOTOR__
#define __DRIVER_IC_FOR_MOTOR__

class DriverIcForMotor{
	public:
		virtual ~DriverIcForMotor(void){}
		
		/**
		 * モータを動かす
		 * @param pwm	動かす速度
		 */
		virtual void commitPwm(int pwm) = 0;
		
		/**
		 * ブレーキモードにする
		 * @param break	true  : ブレーキモード<br>
		 * 							false : フロートモード
		 */
		virtual void applyBrake(bool brake) = 0;
		
		/**
		 * 現在の速度を返す
		 * @return	現在の速度
		 */
		virtual int  fetchPwm(void) = 0;
		
		/**
		 * 現在ブレーキモードかどうかを返す
		 * @return	ブレーキモード : true<br>
		 *					フロートモード : false<br>
		 */
		virtual bool isBraked(void) = 0;
};

#endif