#include "day02.hpp"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <filesystem>
#include <stdexcept>

namespace advent_of_code::year2015::day02
{

  auto Solution::solve_part1(const std::vector<std::vector<int>>& input) -> int
  {
    int total_area = 0;
    for (const auto& dimensions : input)
    {
      const int length = dimensions[0];
      const int width = dimensions[1];
      const int height = dimensions[2];

      const int side1_area = length * width;
      const int side2_area = length * height;
      const int side3_area = width * height;

      const int surface_area = (2 * side1_area) + (2 * side2_area) + (2 * side3_area);

      const int smallest_side_area = std::min({ side1_area, side2_area, side3_area });

      total_area += (surface_area + smallest_side_area);
    }

    return total_area;
  }

  auto Solution::solve_part2(const std::vector<std::vector<int>>& input) -> int
  {
    int total_area = 0;
    for (const auto& dimensions : input)
    {
      const int length = dimensions[0];
      const int width = dimensions[1];
      const int height = dimensions[2];

      const int side1_perimeter = (2 * length) + (2 * width);
      const int side2_perimeter = (2 * length) + (2 * height);
      const int side3_perimeter = (2 * width) + (2 * height);

      const int volume = length * width * height;
      const int smallest_perimeter = std::min({ side1_perimeter, side2_perimeter, side3_perimeter });

      total_area += (volume + smallest_perimeter);
    }

    return total_area;
  }

  auto Solution::parse_input(const std::vector<std::filesystem::path>& possible_paths) -> std::vector<std::vector<int>>
  {
    std::vector<std::vector<int>> result;  // This will store all the parsed integer sets

    std::ifstream inputFile;
    std::filesystem::path filename;

    // Try each possible path
    for (const auto& path : possible_paths)
    {
      inputFile.open(path);
      if (inputFile.is_open())
      {
        filename = path;
        break;
      }
    }

    // Check if the file was opened successfully
    if (!inputFile.is_open())
    {
      std::cerr << "Error: Could not open any of the files in the input directory" << '\n';
      return result;  // Return an empty vector if file opening failed
    }

    std::string line;  // Variable to hold each line read from the file

    // Read the file line by li
    while (std::getline(inputFile, line))
    {
      std::vector<int> currentLineInts;  // This will store the 3 integers for the current line
      std::stringstream stream(line);        // Renamed ss to stream
      std::string segment;               // Variable to hold each segment after splitting

      // Loop to split the line by 'x'
      // std::getline with a delimiter reads until that delimiter is found
      while (std::getline(stream, segment, 'x'))
      {
        try
        {
          // Convert the segment (string) to an integer and add it to currentLineInts
          currentLineInts.push_back(std::stoi(segment));
        }
        catch (const std::invalid_argument& e)
        {
          std::cerr << "Warning: Invalid number format in line: '" << line << "' - " << e.what() << '\n';
          // Optionally, you might want to skip this line or handle the error differently
          currentLineInts.clear();  // Clear potentially partially parsed data for this line
          break;                    // Exit the inner while loop for this line if a conversion fails
        }
        catch (const std::out_of_range& e)
        {
          std::cerr << "Warning: Number out of range in line: '" << line << "' - " << e.what() << '\n';
          currentLineInts.clear();
          break;
        }
      }

      // After splitting, check if we got exactly 3 integers
      if (currentLineInts.size() == 3)
      {
        result.push_back(currentLineInts);  // Add the parsed integers for this line to the result
      }
      else
      {
        std::cerr << "Warning: Line '" << line << "' does not contain exactly 3 'x' separated integers. Skipping." << '\n';
      }
    }

    inputFile.close();  // Close the file after reading
    return result;      // Return the final vector of vectors
  }

}  // namespace advent_of_code::year2015::day02