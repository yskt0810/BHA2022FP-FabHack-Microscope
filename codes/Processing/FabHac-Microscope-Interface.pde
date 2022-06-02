import processing.video.*; // Videoを扱うライブラリをインポート
import processing.serial.*;


Capture camera; // ライブカメラの映像をあつかうCapture型の変数

Serial port;
int data;

void setup() {
  
  String[] cameras = Capture.list();
  println("Available cameras:");
  for (int i = 0; i < cameras.length; i++) {
    println(i, cameras[i]);
  }
  
  size(1024, 768);
  camera = new Capture(this, 1024, 768, cameras[1]); // Captureオブジェクトを生成
  camera.start();
  
  port = new Serial(this, Serial.list()[2], 9600);
  background(0,0,0);
}

void draw() {
  image(camera, 0, 0); // 画面に表示
  
} 

//カメラの映像が更新されるたびに、最新の映像を読み込む
void captureEvent(Capture camera) {
  camera.read();
}


void keyPressed(){
  
  if (key == 'u'){
    
    port.write('U');
    
  }else if(key == 'd'){
    
    port.write('D');
  
  }else if(key == 'l'){
    port.write('L');
  }else if(key == 's'){
    port.write('S'); 
  }
}
