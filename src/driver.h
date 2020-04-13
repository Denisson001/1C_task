#pragma once

#include <iostream>

class Driver {
public:
  void Driver(std::istream &input_stream, std::ostream &output_stream);

private:
  std::istream &input_stream_;
  std::ostream &output_stream_;
};