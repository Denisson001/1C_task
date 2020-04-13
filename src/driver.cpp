#include "driver.h"
#include "autocompleter.h"
#include "parser.h"

void Driver::Run(std::istream &input_stream, std::ostream &output_stream) {
  Parser parser;
  Autocompleter autocompleter;

  while (true) {
    Request request = ReadRequest(input_stream);
    if (request.type == RequestType::Empty) {
      break;
    }

    switch (request.type) {
      case RequestType::AddText: {
        const auto words = parser.ParseText(request.body);
        for (const auto &word : words) {
          autocompleter.AddWord(word);
        }
        break;
      }
      case RequestType::AskWord: {
        PrintWord(output_stream, autocompleter.CompleteWord(request.body));
        break;
      }
      case RequestType::AppendWord: {
        PrintWord(output_stream, autocompleter.AppendWord(request.body));
        break;
      }
    }
  }
}

Request Driver::ReadRequest(std::istream &input_stream) {
  std::string line;
  getline(input_stream, line);
  if (line.size() == 0) {
    return {RequestType::Empty, ""};
  }
  if (line.size() < 2) {
    throw std::logic_error("Bad request");
  }

  Request request;
  if (line[0] == '+') {
    request.type = RequestType::AddText;
  }
  if (line[0] == '?') {
    request.type = RequestType::AskWord;
  }
  if (line[0] == '#') {
    request.type = RequestType::AppendWord;
  }

  request.body = line.substr(2, line.size());
  return request;
}

void Driver::PrintWord(std::ostream &output_stream, const std::string &word) {
  output_stream << word << std::endl;
}