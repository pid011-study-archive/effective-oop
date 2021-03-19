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

    // Ŭ���� �ν��Ͻ��� ����� �̹����� ������ ��ġ�� ����Ѵ�.
    void ShowImage(Vector3 pos);

private:
    const char* _imagePath;
};

class PuzzleBlock
{
public:
    // ������ �ʱ�ȭ�Ѵ�.
    PuzzleBlock(Vector3 pos, ColorType color, int score, BlockState state, Image blockImage)
        : _position(pos), _color(color), _score(score), _state(state), _image(blockImage) { }

    // ������ ��ġ�� �ű��.
    void Move();

    // ������ �ı��ϴ� ������ �����Ѵ�.
    void Destroy();

    // ������ ��ġ�� ��ȯ�Ѵ�.
    Vector3 Position() { return _position; }

    // ������ ���� ������ ��ȯ�Ѵ�.
    ColorType Color() { return _color; }

    // ������ �ı��� �� ��� ������ ��ȯ�Ѵ�.
    int BlockScore() { return _score; }

    // ������ ���� ���¸� ��ȯ�Ѵ�.
    BlockState State() { return _state; }

    // ������ ���� �̹����� ��ȯ�Ѵ�.
    Image BlockImage() { return _image; }

    // ������ ���� ���¸� �����Ѵ�.
    void SetState(BlockState state) { _state = state; }

    // ������ ���� �̹����� �����Ѵ�.
    void SetImage(Image blockImage) { _image = blockImage; }

private:
    Vector3 _position;
    ColorType _color;
    int _score;
    BlockState _state;
    Image _image;
};