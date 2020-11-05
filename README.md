# psd

A C++17 STL loader for files in Adobe's PSD format.  

The format specification can be found here:  
https://www.adobe.com/devnet-apps/photoshop/fileformatashtml/#50577409_pgfId-1036097

# usage

```cpp
#include "psd.h"

// ...

// create an instance of your PSD file
PSD psd;
psd.setColorFormat(PSD::ColorFormat::ABGR);
psd.load("my_test.psd");

// iterate through its layers
for (const auto& layer : psd.getLayers())
{
   // ignore layer groups
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
   auto layerData = layer.getImage().getData().data();
}

```