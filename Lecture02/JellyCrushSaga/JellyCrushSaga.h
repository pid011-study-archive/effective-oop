class Vector3
{
public:
    Vector3(int x, int y, int z) : _x(x), _y(y), _z(z) {};
    void SetX(int x) { _x = x; }
    void SetY(int y) { _y = y; }
    void SetZ(int z) { _z = z; }

    int X() { return _x; }
    int Y() { return _y; }
    int Z() { return _z; }

private:
    int _x, _y, _z;
};

enum class ColorType
{
    Red,
    Green,
    Blue
};

enum class BlockState
{
    Single,
    Linked
};

class Image
{
public:
    Image(const char* imagePath);

    // 클래스 인스턴스에 저장된 이미지를 지정된 위치에 출력한다.
    void ShowImage(Vector3 pos);

private:
    const char* _imagePath;
};

class PuzzleBlock
{
public:
    // 퍼즐을 초기화한다.
    PuzzleBlock(Vector3 pos, ColorType color, int score, BlockState state, Image blockImage)
        : _position(pos), _color(color), _score(score), _state(state), _image(blockImage) { }

    // 퍼즐의 위치를 옮긴다.
    void Move();

    // 퍼즐을 파괴하는 동작을 실행한다.
    void Destroy();

    // 퍼즐의 위치를 반환한다.
    Vector3 Position() { return _position; }

    // 퍼즐의 색상 종류를 반환한다.
    ColorType Color() { return _color; }

    // 퍼즐이 파괴될 시 얻는 점수를 반환한다.
    int BlockScore() { return _score; }

    // 퍼즐의 현재 상태를 반환한다.
    BlockState State() { return _state; }

    // 퍼즐의 현재 이미지를 반환한다.
    Image BlockImage() { return _image; }

    // 퍼즐의 현재 상태를 변경한다.
    void SetState(BlockState state) { _state = state; }

    // 퍼즐의 현재 이미지를 변경한다.
    void SetImage(Image blockImage) { _image = blockImage; }

private:
    Vector3 _position;
    ColorType _color;
    int _score;
    BlockState _state;
    Image _image;
};