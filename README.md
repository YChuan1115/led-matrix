# Raspberry Pi 利用 GPIO 控制 32x32 RGB LED 陣列

  

**實驗名稱:**
    GPIO 控制 32x32 RGB LED Matrix

**實驗目的:**
    了解在 Pi 板上，寫 C 語言控制 GPIO 來控制 32 x 32 RGB LED Matrix 的方法。

**使用材料及設備:**
    市售 32x32 RGB LED 陣列板子
    Raspberry Pi 板
    連接線

**原理介紹:**


  此 32x32 RGB LED 陣列板子的橫向 (x-軸) LED 亮暗控制器是由 32 位元位移暫存器來操作，
    而縱向 (y-軸) LED 亮暗控制器是由一個 4 bit 控制16 路的多路分用器來操作。故我們在這個實驗需要練習:
     用程式控制 32 bit 位移暫存器、用程式控制16 路的多路分用器。最後在32x32 RGB LED Matrix 上面顯示圖案。
     下面分別說明位移暫存器和多路分用器的作用。

   - 位移暫存器 IC 是一種序列輸入轉換成並列輸出的一種 IC。
    基本功能可以用三支 pin 腳來達成資料輸入: 資料 (DATA pin ) 、CLOCK (CLK pin)、觸發 (LAT pin)。
    跟據IC的規格，輸出 bit 數就是 輸出 pin 腳數目。在此例當中，輸出為 32 bit ，
    故有 32 支 pin 腳依序控制了LED Matrix 的 x-軸向 32 個的 LED 的亮暗 (1 為亮，0 為暗)。
    而操作方式在下節會說明。

   -  多路分用器 IC 是一種由少數 pin 控制要輸出或接地的pin腳。在此例中，
    輸入為四根 pin ，代表著 4 個輸入 bit。而輸出有 16 根，代表著 16 個 bit。
    而四個輸入的 bit 可以表現出來的數值為0~15 (0b0000 ~ 0x1111)，所以剛好可以控制第幾個輸出腳為導通，其他的輸出腳為不導通。
    而操作方式在下節會說明。
    
    
   
 [更多說明](http://blog.ittraining.com.tw/2015/03/raspberry-pi-gpio-32x32-rgb-led.html)
