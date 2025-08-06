<div style="text-align: center;">
  <h1 style="text-align: center;">My Competitive Programming Journey 🚀</h1>
  <img src="https://gifdb.com/images/file/lightning-mcqueen-doc-hudson-speed-cars-1adpw3haxlr8wwgr.gif" alt="Lightning McQueen and Doc Hudson Speed Cars GIF" width="300">
</div>

This repository is my personal log for tracking my progress in competitive programming, organizing coding problems from platforms like LeetCode, Codeforces, and others. Using a structured folder system 📁 and GitHub Issues 📋, I document my attempts and solutions to stay organized and monitor my growth.

## About My Journey 🌟

`my-cp-journey` is my personal space to:

- **Track Progress** 📈: Log every step of my competitive programming journey, from initial attempts (`try`) to completed solutions (`solve`).
- **Organize Problems** 🗂️: Categorize solutions into solo and team efforts, with clear links to problem sources.
- **Learn and Improve** 🧠: Use GitHub Issues to flag problems for review or optimization, reflecting on my approaches.
- **Share Knowledge** 🌍: Share my solutions and progress with others, inviting feedback or collaboration.

This repository is primarily for my growth but welcomes anyone who wants to explore, learn from, or contribute to my competitive programming efforts! 😊

## Repository Structure 📁

**Note**: I am still modifying file names to improve navigation and make it easier to find specific problems. Updates are ongoing! 🔧  
**Note**: Most of my work and sheet solving is currently under my favorite team folder, "1 2 Tree", where I focus my collaborative efforts and problem sets. 🌳

The repository is organized into two main folders to keep problems tidy:

- **`solo/`** 🧑‍💻: My individual solutions to competitive programming problems, named using problem codes (e.g., `123A.cpp` for a Codeforces problem) and linked to sources via issues or commits.
- **`teams/`** 👥: Collaborative solutions from coding contests or group practice, also using problem codes (e.g., `456B.cpp`).

I use problem codes for file naming (e.g., `123A` for Codeforces, `1A` for AtCoder) to align with competition formats, and I add topic-based labels (e.g., `graph`, `dp`, `greedy`) to issues for better organization.

## Tracking Progress with Issues 📋

I use GitHub Issues to systematically track my progress, automated by a [GitHub Actions workflow](.github/workflows/issue-manager.yml) 🤖.

### Closing Issues ✅

- When I push a commit with "solve" and the same problem URL (e.g., `git commit -m "Solve problem https://codeforces.com/problemset/problem/123/A"`), the matching issue is closed.
- The issue’s body is updated with: `Closed due to "solve" commit with matching problem URL: <URL>`.

### Organizing with Labels 🏷️

- **Default Labels**:
  - `auto-generated`: Marks issues created by the workflow.
  - `review`: Flags problems for further review or optimization.
- **Custom Labels**: I add labels like `AtCoder`, `codeforces`, `difficulty-easy`, `difficulty-medium`, or `difficulty-hard` to categorize problems, plus topic-based labels (e.g., `graph`, `dp`, `greedy`) to reflect problem themes.

To explore my progress:

- Visit the [Issues tab](https://github.com/AmiraKhalid04/my-cp-journey/issues) 🔍.
- Filter by labels (e.g., `CF`, `difficulty-hard`, `graph`) or search for a problem URL (e.g., `from:codeforces.com`).

## Contributing 🤝

I welcome contributions to enhance my journey with solutions, optimizations, or feedback! 🚀 Follow these steps to contribute:

### Steps to Contribute 🚶

1. **Fork the Repository** 🍴:
   - Click "Fork" on GitHub to create a copy of `my-cp-journey`.
2. **Clone Your Fork** 📥:
   ```bash
   git clone https://github.com/<your-username>/my-cp-journey.git
   cd my-cp-journey
   ```
3. **Create a Branch** 🌿:
   ```bash
   git checkout -b <branch-name>
   ```
   Use a descriptive name, e.g., `add-123A-solution` or `optimize-456B`.
4. **Add a Solution** ✍️:
   - Place solo solutions in `solo/<platform>/` and team solutions in `teams/<platform>/` (e.g., `teams/"1 2 Tree"/`).
   - Name files using problem codes (e.g., `123A.cpp`, `456B.cpp`).
   - Include a comment with the problem URL and description:
     ```python
     # Problem: Problem 123A (https://codeforces.com/problemset/problem/123/A)
     # Description: Solve the given problem description.
     # Solution code here
     ```
5. **Commit with "try" or "solve"** 📌:
   - For an attempt:
     ```bash
     git commit -m "Try solution for problem https://codeforces.com/problemset/problem/123/A"
     ```
   - For a completed solution:
     ```bash
     git commit -m "Solve problem https://codeforces.com/problemset/problem/123/A"
     ```
   - The workflow creates or closes issues automatically 🤖.
6. **Push and Create a Pull Request** 🚀:
   ```bash
   git push origin <branch-name>
   ```
   - Open a pull request on GitHub, describing your changes.
   - Reference the relevant issue if applicable.
7. **Add Labels to Issues** 🏷️:
   - Use labels like `leetcode`, `codeforces`, `difficulty-easy`, plus topic-based labels (e.g., `graph`, `dp`) to categorize problems.

### Contribution Guidelines 📝

- Use problem codes for file names (e.g., `123A.cpp`).
- Include the problem URL in commit messages and file comments.
- Document code with comments explaining the approach.
- Test solutions before committing.

## License 📜

This project is licensed under the [MIT License](LICENSE). Feel free to use, modify, and share the code, provided the license is included.

## Contact 📬

Have questions or ideas to improve this repository?

- **Issues** 📋: Open an issue in the [Issues tab](https://github.com/AmiraKhalid04/my-cp-journey/issues).
- **Codeforces** 😺: Reach out to [amira928](https://codeforces.com/profile/amira928).

---
