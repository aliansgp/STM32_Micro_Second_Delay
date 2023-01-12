# STM32_Micro_Second_Delay
## Intro :
This project create us-delay with timer
Made with STM32CubeMX with `STM32CubeIDE Toolchain`
Selected microcontroller is `STM32F4xx` and HAL library has been used.
## Clock configuration :
Clock configured 168MH with PLL :

![Clock settings](https://user-images.githubusercontent.com/38432834/212073054-0cf6aed0-62a9-4882-9bd9-ee6fa1f3c6c9.PNG)

## Create Project :
TIM1 settings:

![TIM1_Settings](https://user-images.githubusercontent.com/38432834/212072152-5a6494fa-04e5-499e-a071-9a5ce04ecaf9.PNG)

Just set clock source, internal clock

PSC and counter period , MAX Value

## Code algorithm :
Algorithm is so simple:

First start the timer (in this code, Timer 1),
```
HAL_TIM_Base_Start(&htim1);
```
Then reset CNT value, 
```
htim1.Instance->CNT=0;
```
And wait for CNT to reach us(input) value (with while). 
```
while(htim1.Instance->CNT < us);
```
## Result :
In main function, toggle GPIOE port, pin 15 every 20 micro-second and result:

![monitor](https://user-images.githubusercontent.com/38432834/212074441-14214de6-1288-4f58-9ad2-6b9025f6e7c8.png)


## Notes :
### Accuracy :
Result was not exactly 20us because HAL-library functions have a delay itself and if it was very large, you can calibre it manually:

For example if we want 40us delay and every time we got ~42 us, write this code before the while:
```
us -= 2;
```
### Other method :
Also you can library to make us-delay with HAL-library functions delay rather than Timer.

For example, write this code and monitor the delay and calibre it with changing the `value` to make one us delay :
```
void us_delay(int us){
value = 10000;
delay = us * value;
for(int i;i < delay;i++);

}
```

