class Play {
public:
  Play();
  void start();
  void game(String step);
private:
  int found_led(String coord);
  void pawn_move(String x, String y);
  bool checkGame(String x, String y);
  bool check_step(String x, String y);
  bool check_kill(String x, String y);
  bool step_ladies(String x, String y);
  void ladies(String x, String y);
  void blink(String x);
  void error();
  void ok();
};