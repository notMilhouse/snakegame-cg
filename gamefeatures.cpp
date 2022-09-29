class GamePos {
    public:
        GamePos() {
            posX = 15;
            posY = 15;
        }

        GamePos(int x, int y) {
            posX = x;
            posY = y;
        }

        void setPos(int x, int y) {
            posX = x;
            posY = y;
        }

        int getX() {
            return posX;
        }

        int getY() {
            return posY;
        }

        GamePos* incrementX(int increment) {
            posX += increment;

            return this;
        }

        GamePos* incrementY(int increment) {
            posY += increment;
            
            return this;
        }
    
    private:
        int posX;
        int posY;
};

enum class DirectionState {
    UP,
    DOWN,
    LEFT,
    RIGHT
};

class Direction {
    public:
        Direction() {
            dirX = 1;
            dirY = 0;
            state = DirectionState::RIGHT;
        }

        void toUp() {
            dirX = 0;
            dirY = 1;
            state = DirectionState::UP;
        }

        void toDown() {
            dirX = 0;
            dirY = -1;
            state = DirectionState::DOWN;
        }

        void toLeft() {
            dirX = -1;
            dirY = 0;
            state = DirectionState::LEFT;
        }

        void toRight() {
            dirX = 1;
            dirY = 0;
            state = DirectionState::RIGHT;
        }

        void stop()
        {
            dirX = 0;
            dirY = 0;
        }

        short getDirX() {
            return dirX;
        }

        short getDirY() {
            return dirY;
        }

        DirectionState getState() {
            return state;
        }

    private:
        short dirX;
        short dirY;
        DirectionState state;
};

class GameObject {
    public:
        GameObject(GamePos p, Direction d)
        {
            pos = p;
            direction = d;
        };

        GamePos getPos()
        {
            return pos;
        }

        Direction getDir()
        {
            return direction;
        }

    protected:
        GamePos pos;
        Direction direction;
};