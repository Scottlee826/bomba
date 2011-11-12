
#include <config.h>

#include <irrlicht/irrlicht.h>

#include <memory>
#include <iostream>
#include <sstream>

using namespace irr;


const int WIDTH = 320;
const int HEIGHT = 240;

int main() {
  std::cout << "\\Weeeeee/" << std::endl;

  using core::dimension2d;
  
  SIrrlichtCreationParameters params;
  params.AntiAlias = true;
  params.WithAlphaChannel = true;
  params.DeviceType = EIDT_BEST;
  params.DriverType = video::EDT_OPENGL;
  params.WindowSize = dimension2d<u32>(WIDTH,HEIGHT);
  params.Doublebuffer = true;
  params.Bits = 32;
  params.ZBufferBits = 16;
  params.Fullscreen = false;
  params.Vsync = params.Fullscreen;

  std::auto_ptr<IrrlichtDevice> device(createDeviceEx(params));
  
  std::string title = std::string("Bomba ") + BUILD_VERSION_MAJOR + "." + 
    + BUILD_VERSION_MINOR + "." + BUILD_VERSION_REVISION;
  std::wstring capt;
  capt.assign(title.begin(), title.end());

  device->setWindowCaption(capt.c_str());

  while(device->run()) {
    irr::video::IVideoDriver* pDriver = device->getVideoDriver();
    pDriver->beginScene(true, true, video::SColor(255,100,101,140));
    pDriver->endScene();
  }

  device.release()->drop();
}
