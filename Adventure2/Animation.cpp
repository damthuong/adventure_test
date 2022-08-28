#include "Animation.h" 



Animation::Animation() {

	_currentTime = 0.f;

	_currentFrame = sf::Vector2i(0, 0);
	_frameNum = sf::Vector2i(1, 1);
	_frameTime = 0;

}

void Animation::Init(sf::Texture& texture, sf::Vector2i frameNum, float frameTime) {

	_frameNum = frameNum;
	_frameTime = frameTime;

	this->setTexture(texture);



	CaculatorRectSize();

	CaculatorRectUV();

	ApplyRect();

}

Animation::~Animation() {}



void Animation::Update(float deltaTime) {
	_currentTime += deltaTime;
	if (_currentTime >= _frameTime) {

		_currentFrame.x++;

		if (_currentFrame.x == _frameNum.x) {

			_currentFrame.x = 0;

		}

		CaculatorRectUV();

		ApplyRect();

		_currentTime -= _frameTime;



	}

}

void Animation::CaculatorRectSize() {

	_rectSize = sf::Vector2i(this->getTexture()->getSize().x / _frameNum.x, this->getTexture()->getSize().y / _frameNum.y);

}

void Animation::CaculatorRectUV() {

	_rectUV.x = _currentFrame.x * _rectSize.x;

	_rectUV.y = _currentFrame.y * _rectSize.y;

}

void Animation::ApplyRect() {

	_rect = sf::IntRect(_rectUV, _rectSize);

	this->setTextureRect(_rect);

}

void Animation::Reset()
{
	{
		_currentFrame.x = 0;
		_currentTime = 0.f;
	}
}
