#pragma once

#include <iostream>

enum RequestType {
  Empty,
  AddText,
  AskWord,
  AppendWord
};

struct Request {
  RequestType type;
  std::string body;
};

class Driver {
public:
  void Run(std::istream &input_stream, std::ostream &output_stream);

private:
  void PrintWord(std::ostream &output_stream, const std::string& word);
  Request ReadRequest(std::istream &input_stream);
};