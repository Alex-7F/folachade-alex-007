check_program_compilation:
    runs-on: ubuntu-latest
    timeout-minutes: 2
    container: epitechcontent/epitest-docker:latest
    needs: check_coding_style
    steps:
      - name: Checkout GH repository
        uses: actions/checkout@master
        with:
          repository: ''

      - name: Compile repository
        run: |
          make
          make clean

  run_tests:
    needs: [check_program_compilation]
    name: "Run test for hero"
    runs-on: ubuntu-latest
    container:
      image: epitechcontent/epitest-docker:latest
    steps:
      - uses: actions/checkout@v3
      - id: run_tests
        run: make tests_run
        timeout-minutes: 2
