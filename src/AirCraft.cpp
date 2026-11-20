#include "AirCraft.h"


namespace
{
    Textures::ID getTextureID(AirCraft::Type type)
    {
    switch(type)
    {
        case AirCraft::Type::Eagle :
            return Textures::ID::Eagle;
        
        case AirCraft::Type::Raptor :
            return Textures::ID::Raptor;
    }
    }

}
AirCraft::AirCraft(Type type, const TextureHolder& textures) 
	: type_{ type }
	, sprite_{ textures.getResource(getTextureID(type)) }
{
	sf::FloatRect boundaries = sprite_.getLocalBounds();
	sprite_.setOrigin(boundaries.getCenter());
}

void AirCraft::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(sprite_, states);
}