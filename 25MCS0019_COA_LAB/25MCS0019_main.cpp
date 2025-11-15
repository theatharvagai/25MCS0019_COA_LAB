#include <stdio.h>
#include <cstdlib>
#include <omp.h>

// Including all your custom header files
#include "00_colours.h"
#include "helloworld_srl.h"
#include "helloworld_prl.h"
#include "ret_tid_helloworld.h"
#include "run_time_environment_routines.h"
#include "031_wsc_for_num_square.h"
#include "040_wsc_section_pp2.h"
#include "050_Scheduling_Static.h"
#include "050_Scheduling_Dynamic.h"
#include "050_Scheduling_Guided.h"
#include "060_Data_env_constructs.h"
#include "061_dec_critical.h"
#include "061_dec_reduction.h"

int main()
{
    int choice;

    printf("\n");

    // Printing fancy header using colours
    fn_red();
    printf("*****************************************************************************************************************\n");
    fn_reset();

    fn_blue();
    printf("\t\t\t\tMACSE517-COMPUTER ARCHITECTURE AND ORGANISATION LAB PROGRAMS\n");
    printf("\t\t\t\t\t\t\t    BY\n");
    fn_reset();

    fn_yellow();
    printf("\n");
    printf("\t\t\t\t\t    Reg.No:25MCS0019  Name:Atharva Gai\n");
    printf("\n");
    fn_reset();

    fn_blue();
    printf("\t\t\t\t\t  Submitted as part of Lab assessment to\n");
    fn_magenta();
    printf("\t\t\t\t\t\t Dr.M.RAJASEKHARA BABU\n");
    fn_reset();

    fn_blue();
    printf("\t\t\t\t\tSCHOOL OF COMPUTER SCIENCE AND ENGINEERING \n");
    printf("\t\t\t           VELLORE INSTITUTE OF TECHNOLOGY(VIT),VELLORE-632014\n");
    printf("\t\t\t\t\t\t    NOVEMBER 2025\n");
    fn_reset();

    fn_red();
    printf("*****************************************************************************************************************\n");
    fn_reset();

    // ---------------- MAIN MENU LOOP ---------------------
    // do-while ensures menu keeps running until user selects Exit
    do
    {
        fn_green();
        printf("------------------------------------------------------------------------------------------------------------------\n");
        printf("1. Exit  2. Parallel Construct Program\t3. Run-Time Environment Routines\t4. Loop Work Sharing Construct\n");
        printf("\n");
        printf("5. Sections & Single Worksharing Constructs\t6. Scheduling techniques\t7. Data Evironment Constructs\n");
        fn_reset();

        fn_yellow();
        printf("------------------------------------------------------------------------------------------------------------------\n");
        fn_reset();

        printf("Enter choice: ");
        scanf_s("%d", &choice);

        switch (choice)
        {
            // ==============================================================
            // 1. EXIT PROGRAM
            // ==============================================================
        case 1:
            exit(0);
            break;

            // ==============================================================
            // 2. PARALLEL CONSTRUCT PROGRAM
            // ==============================================================
        case 2:
        {
            int ch2;

            do
            {
                fn_yellow();
                printf("20. Exit  21. Serial\t22. Parallel\t23. Both\n");
                fn_reset();

                printf("Enter your choice: ");
                scanf_s("%d", &ch2);

                switch (ch2)
                {
                case 20:
                    printf("Back to MAIN MENU\n");
                    break;

                case 21:
                    // Serial "Hello World" program
                    fn_helloworld_srl();
                    break;

                case 22:
                    // Parallel "Hello World" program
                    fn_helloworld_prl();
                    break;

                case 23:
                    // Run both serial and parallel
                    fn_helloworld_srl();
                    fn_helloworld_prl();
                    break;

                default:
                    printf("Invalid Choice\n");
                    break;
                }

            } while (ch2 != 20);

            break;
        }

        // ==============================================================
        // 3. RUN TIME ENVIRONMENT ROUTINES + PERFORMANCE ANALYSIS
        // ==============================================================
        case 3:
        {
            int ch3;

            do
            {
                fn_yellow();
                printf("30. Exit  31. Performance Analysis\t32. Runtime Environment Routines\n");
                fn_reset();

                printf("Enter your choice: ");
                scanf_s("%d", &ch3);

                switch (ch3)
                {
                    // --------------- Return to previous menu ---------------
                case 30:
                    printf("Back to MAIN MENU\n");
                    break;

                    // --------------- 31. Performance Analysis ---------------
                case 31:
                {
                    printf("Performance Analysis\n");
                    int ch31;

                    do
                    {
                        fn_cyan();
                        printf("310. Exit  311. Serial\t312. Parallel\t313. Both\n");
                        fn_reset();

                        printf("Enter your choice: ");
                        scanf_s("%d", &ch31);

                        switch (ch31)
                        {
                        case 310:
                            printf("Back to Previous MENU\n");
                            break;

                        case 311:
                            printf("Serial\n");
                            fn_ret_tid_helloworld_srl();
                            break;

                        case 312:
                            printf("Parallel\n");
                            fn_ret_tid_helloworld_prl();
                            break;

                        case 313:
                            printf("Both Serial and Parallel\n");
                            fn_ret_tid_helloworld_srl();
                            fn_ret_tid_helloworld_prl();
                            break;

                        default:
                            printf("Invalid Choice\n");
                            break;
                        }

                    } while (ch31 != 310);

                    break;
                }

                // --------------- 32. Runtime Environment Menu ---------------
                case 32:
                {
                    printf("Runtime Routine\n");
                    int ch32;

                    do
                    {
                        fn_cyan();
                        printf("320. Exit  321. omp_set_num_threads\t322. omp_get_num_threads\t323. omp_get_max_threads\n");
                        printf("324. omp_get_thread_num\t325. omp_get_num_procs\t326. omp_in_parallel\t327. omp_set_dynamic\n");
                        printf("328. omp_get_dynamic\t329. omp_set_nested\t3210. omp_get_nested\n");
                        fn_reset();

                        printf("Enter your choice: ");
                        scanf_s("%d", &ch32);

                        switch (ch32)
                        {
                        case 320:
                            printf("Back to Previous MENU\n");
                            break;

                        case 321:
                        {
                            int n;
                            printf("Enter the Number of threads: ");
                            scanf_s("%d", &n);
                            fn_rter_omp_set_num_threads(n);
                            break;
                        }

                        case 322: fn_rter_omp_get_num_threads(); break;
                        case 323: fn_rter_omp_get_max_threads(); break;
                        case 343: fn_rter_omp_get_max_threads(); break;
                        case 324: fn_rter_omp_get_thread_num(); break;
                        case 325: fn_rter_omp_get_num_procs(); break;
                        case 326: fn_rter_omp_in_parallel(); break;
                        case 327: fn_rter_omp_set_dynamic(1); break;
                        case 328: fn_rter_omp_get_dynamic(); break;
                        case 329: fn_rter_omp_set_nested(1); break;
                        case 3210: fn_rter_omp_get_nested(); break;

                        default:
                            printf("Invalid Choice\n");
                            break;
                        }

                    } while (ch32 != 320);

                    break;
                }

                default:
                    printf("Invalid Choice\n");
                    break;
                }

            } while (ch3 != 30);

            break;
        }

        // ==============================================================
        // 4. LOOP WORK SHARING: NUMBER SQUARE
        // ==============================================================
        case 4:
        {
            int ch4;

            fn_blue();
            printf("Parallelization of square of an array and performance analysis\n");
            fn_reset();

            do
            {
                fn_yellow();
                printf("40. Exit  41. Serial\t42. Parallel\t43. Both\n");
                fn_reset();

                printf("Enter your choice: ");
                scanf_s("%d", &ch4);

                switch (ch4)
                {
                case 40:
                    printf("Back to MAIN MENU\n");
                    break;

                case 41:
                    printf("Serial\n");
                    fn_num_square_srl();
                    break;

                case 42:
                    printf("Parallel\n");
                    fn_num_square_prl();
                    break;

                case 43:
                    printf("Both Serial and Parallel\n");
                    fn_num_square_srl();
                    fn_num_square_prl();
                    break;

                default:
                    printf("Invalid Choice\n");
                    break;
                }

            } while (ch4 != 40);

            break;
        }

        // ==============================================================
        // 5. SECTIONS — CALCULATOR FUNCTIONS
        // ==============================================================
        case 5:
        {
            int ch5;

            fn_blue();
            printf("Parallelization of Calculator functions using Sections\n");
            fn_reset();

            do
            {
                fn_yellow();
                printf("50. Exit  51. Serial\t52. Parallel\t53. Both\n");
                fn_reset();

                printf("Enter your choice: ");
                scanf_s("%d", &ch5);

                switch (ch5)
                {
                case 50:
                    printf("Back to MAIN MENU\n");
                    break;

                case 51:
                    printf("Serial\n");
                    serialGame();
                    break;

                case 52:
                    printf("Parallel\n");
                    parallelGame();
                    break;

                case 53:
                    printf("Both Serial and Parallel\n");
                    serialGame();
                    parallelGame();
                    break;

                default:
                    printf("Invalid Choice\n");
                    break;
                }

            } while (ch5 != 50);

            break;
        }

        // ==============================================================
        // 6. SCHEDULING TECHNIQUES (STATIC, DYNAMIC, GUIDED)
        // ==============================================================
        case 6:
        {
            int ch6;

            fn_blue();
            printf("OpenMP Scheduling Techniques\n");
            fn_reset();

            do
            {
                fn_yellow();
                printf("60. Exit  61. Static Scheduling\t62. Dynamic Scheduling\t63. Guided Scheduling\n");
                fn_reset();

                printf("Enter your choice: ");
                scanf_s("%d", &ch6);

                switch (ch6)
                {
                    // ------------------ Static Scheduling ------------------
                case 61:
                {
                    printf("Static Scheduling\n");
                    int ch61;

                    do
                    {
                        fn_cyan();
                        printf("610. Exit  611. Default Static\t612. Static with chunk size 1\t613. Static with chunk size 2\n");
                        fn_reset();

                        printf("Enter your choice: ");
                        scanf_s("%d", &ch61);

                        switch (ch61)
                        {
                        case 610:
                            printf("Back to Previous MENU\n");
                            break;

                        case 611:
                            printf("Default Static Scheduling\n");
                            fn_default_Static_Scheduling();
                            break;

                        case 612:
                            printf("Static Scheduling with chunk size 1\n");
                            fn_static_01();
                            break;

                        case 613:
                            printf("Static Scheduling with chunk size 2\n");
                            fn_static_02();
                            break;

                        default:
                            printf("Invalid Choice\n");
                            break;
                        }

                    } while (ch61 != 610);

                    break;
                }

                // ------------------ Dynamic Scheduling ------------------
                case 62:
                {
                    printf("Dynamic Scheduling\n");
                    int ch62;

                    do
                    {
                        fn_cyan();
                        printf("620. Exit  621. Dynamic with chunk size 1\t622. Dynamic with chunk size 2\n");
                        fn_reset();

                        printf("Enter your choice: ");
                        scanf_s("%d", &ch62);

                        switch (ch62)
                        {
                        case 620:
                            printf("Back to Previous MENU\n");
                            break;

                        case 621:
                            printf("Dynamic Scheduling with chunk size 1\n");
                            fn_dynamic_01();
                            break;

                        case 622:
                            printf("Dynamic Scheduling with chunk size 2\n");
                            fn_dynamic_02();
                            break;

                        default:
                            printf("Invalid Choice\n");
                            break;
                        }

                    } while (ch62 != 620);

                    break;
                }

                // ------------------ Guided Scheduling ------------------
                case 63:
                {
                    printf("Guided Scheduling\n");
                    int ch63;

                    do
                    {
                        fn_cyan();
                        printf("630. Exit  631. Guided with chunk size 1\t632. Guided with chunk size 2\n");
                        fn_reset();

                        printf("Enter your choice: ");
                        scanf_s("%d", &ch63);

                        switch (ch63)
                        {
                        case 630:
                            printf("Back to Previous MENU\n");
                            break;

                        case 631:
                            printf("Guided Scheduling with chunk size 1\n");
                            fn_guided_01();
                            break;

                        case 632:
                            printf("Guided Scheduling with chunk size 2\n");
                            fn_guided_02();
                            break;

                        default:
                            printf("Invalid Choice\n");
                            break;
                        }

                    } while (ch63 != 630);

                    break;
                }

                case 60:
                    printf("Back to MAIN MENU\n");
                    break;

                default:
                    printf("Invalid Choice\n");
                    break;
                }

            } while (ch6 != 60);

            break;
        }

        // ==============================================================
        // 7. DATA ENVIRONMENT CLAUSES (Shared, Private, Critical, Reduction)
        // ==============================================================
        case 7:
        {
            int ch7;

            fn_blue();
            printf("Data Environment Constructs in OpenMP\n");
            fn_reset();

            do
            {
                fn_yellow();
                printf("70. Exit  71. Shared & Private Clauses\t72. Critical Section\t73. Reduction Clause\n");
                fn_reset();

                printf("Enter your choice: ");
                scanf_s("%d", &ch7);

                switch (ch7)
                {
                    // ------------------ Shared & Private ------------------
                case 71:
                {
                    printf("Shared & Private Clauses\n");
                    int ch71;

                    do
                    {
                        fn_cyan();
                        printf("710. Exit  711. Serial\t712. Parallel\t713. Both\n");
                        fn_reset();

                        printf("Enter your choice: ");
                        scanf_s("%d", &ch71);

                        switch (ch71)
                        {
                        case 710:
                            printf("Back to Previous MENU\n");
                            break;

                        case 711:
                            printf("Serial\n");
                            fn_run_vector_addition_srl();
                            break;

                        case 712:
                            printf("Parallel\n");
                            fn_run_vector_addition_prl();
                            break;

                        case 713:
                            printf("Both Serial and Parallel\n");
                            fn_run_vector_addition_srl();
                            fn_run_vector_addition_prl();
                            break;

                        default:
                            printf("Invalid Choice\n");
                            break;
                        }

                    } while (ch71 != 710);

                    break;
                }

                // ------------------ Critical Section ------------------
                case 72:
                {
                    printf("Critical Section\n");
                    int ch72;

                    do
                    {
                        fn_cyan();
                        printf("720. Exit  721. Serial\t722. Parallel\t723. Both\n");
                        fn_reset();

                        printf("Enter your choice: ");
                        scanf_s("%d", &ch72);

                        switch (ch72)
                        {
                        case 720:
                            printf("Back to Previous MENU\n");
                            break;

                        case 721:
                            printf("Serial\n");
                            fn_dec_critical_srl();
                            break;

                        case 722:
                            printf("Parallel\n");
                            fn_dec_critical_prl();
                            break;

                        case 723:
                            printf("Both Serial and Parallel\n");
                            fn_dec_critical_srl();
                            fn_dec_critical_prl();
                            break;

                        default:
                            printf("Invalid Choice\n");
                            break;
                        }

                    } while (ch72 != 720);

                    break;
                }

                // ------------------ Reduction Clause ------------------
                case 73:
                {
                    printf("Reduction Clause\n");
                    int ch73;

                    do
                    {
                        fn_cyan();
                        printf("730. Exit  731. Serial\t732. Parallel\t733. Both\n");
                        fn_reset();

                        printf("Enter your choice: ");
                        scanf_s("%d", &ch73);

                        switch (ch73)
                        {
                        case 730:
                            printf("Back to Previous MENU\n");
                            break;

                        case 731:
                            printf("Serial\n");
                            fn_dec_reduction_srl();
                            break;

                        case 732:
                            printf("Parallel\n");
                            fn_dec_reduction_prl();
                            break;

                        case 733:
                            printf("Both Serial and Parallel\n");
                            fn_dec_reduction_srl();
                            fn_dec_reduction_prl();
                            break;

                        default:
                            printf("Invalid Choice\n");
                            break;
                        }

                    } while (ch73 != 730);

                    break;
                }

                case 70:
                    printf("Back to MAIN MENU\n");
                    break;

                default:
                    printf("Invalid Choice\n");
                    break;
                }

            } while (ch7 != 70);

            break;
        }

        default:
            printf("Invalid Choice\n");
            break;
        }

    } while (choice != 1);

    return 0;
}
