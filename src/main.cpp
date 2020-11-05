#include "psd.h"

#include <iostream>

int main(int /*argc*/, char* /*argv*/[])
{
   PSD psd;
   psd.setColorFormat(PSD::ColorFormat::ABGR);
   psd.load("my_test.psd");

   for (const auto& layer : psd.getLayers())
   {
      // skip groups
      if (layer.getSectionDivider() != PSD::Layer::SectionDivider::None)
      {
         continue;
      }

      // evaluate layer properties
      std::cout
         << "name:    " << layer.getName() << std::endl
         << "opacity: " << layer.getOpacity() << std::endl
         << "width:   " << layer.getWidth() << std::endl
         << "height:  " << layer.getHeight() << std::endl
         << "left:    " << layer.getLeft() << std::endl
         << "top:     " << layer.getTop() << std::endl;

      // do something with the raw layer data
      (void)layer.getImage().getData().data();
   }

   return 0;
}
