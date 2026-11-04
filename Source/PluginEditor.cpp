
const int margin=18,gap=12,top=122,w=(getWidth()-2*margin-2*gap)/3,h=270;

for(int i=0;i<6;++i)
{
    int x=margin+(i%3)*(w+gap);
    int y=top+(i/3)*(h+gap);

    // FIX: фигурные скобки вместо круглых
    juce::Rectangle<float> r{
        float(x), float(y), float(w), float(h)
    };

    g.setColour(dark);
    g.fillRoundedRectangle(r,12);

    g.setColour(juce::Colour(0xff2b374b));
    g.drawRoundedRectangle(r,12,1);

    g.setColour(colors[i]);
    g.fillRoundedRectangle(r.removeFromTop(4),2);

    g.setColour(colors[i].withAlpha(.10f));
    g.fillEllipse(float(x+w-126),float(y+52),100,100);

    g.setColour(colors[i]);
    g.setFont(juce::Font(juce::FontOptions(14.0f,juce::Font::bold)));
    g.drawText(modules[i],x+18,y+16,w-36,24,juce::Justification::left);

    g.setColour(juce::Colour(0xff263247));

    for(int k=0;k<2;++k)
    {
        float cx=float(x+78+k*132);
        float cy=float(y+142);

        g.fillEllipse(cx-43,cy-43,86,86);

        g.setColour(colors[i].withAlpha(.72f));
        g.drawEllipse(cx-43,cy-43,86,86,2.0f);

        g.setColour(juce::Colour(0xffdce7f7));
        g.drawEllipse(cx-27,cy-27,54,54,1.0f);

        g.setFont(11.0f);
        g.drawText(
            k==0?"CONTROL A":"CONTROL B",
            int(cx-55),y+194,110,18,
            juce::Justification::centred
        );

        g.setColour(juce::Colour(0xff263247));
    }
}
