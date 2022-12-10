import java.util.Arrays;
import java.io.File;
import java.util.Scanner;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.Random;
import java.lang.Math;
import java.nio.file.Path;
import java.nio.file.Paths;

class AWGN_decoder {
    public static void main(String[] args) throws FileNotFoundException, IOException {
        System.out.println();
        //////
        double distance_away = 1.85;
        int num_blocks = 1000;
        //////
        int min_number_of_iters = 6;
        int max_number_of_iters = 50;
        double threshold_value = 5.0;
        //////
        int num_layers = 46;
        double offset = 0.35;
        //////
        String base_mat_filename = "NR_1_7_30.txt"; // n=2040
        int Zc = 30;

        ////////////////////////////////////////////////////////
        double Shannons_limit = -0.53094117634; // R=0.32 // -0.53094117634
        double required_spec = Shannons_limit + distance_away;
        double EbNo_dB = required_spec;

        int[][] base_mat = new int[46][68];
        base_mat = read_base_matrix(base_mat_filename);
        int num_rows = 46;
        int num_cols = 68;
        int k = (num_cols - num_rows) * Zc;
        int n = num_cols * Zc;
        Double temp_double1 = Double.valueOf(k);
        Double temp_double2 = Double.valueOf(n);

        double code_rate = temp_double1 / temp_double2;
        double EbNo_10 = (double) Math.pow(10, (EbNo_dB / 10));
        double sigma = Math.sqrt(1 / (2 * code_rate * EbNo_10));

        int Num_of_non_minus_1s = 0;
        int val;
        for (int i = 0; i < num_rows; i++) {
            for (int j = 0; j < num_cols; j++) {
                val = base_mat[i][j];
                if (val != -1) {
                    Num_of_non_minus_1s++;
                }
            }
        }
        int[] temp_rows_count = new int[num_rows];
        Arrays.fill(temp_rows_count, 0);
        for (int i = 0; i < num_rows; i++) {
            for (int j = 0; j < num_cols; j++) {
                val = base_mat[i][j];
                if (val != -1) {
                    temp_rows_count[i]++;
                }
            }
        }
        int cols_count = 0;
        val = 0;
        for (int i = 0; i < 46; i++) {
            val = temp_rows_count[i];
            if (val > cols_count) {
                cols_count = val;
            }
        }
        double[][] minsum_storage = new double[Zc][cols_count];
        for (double[] row : minsum_storage) {
            Arrays.fill(row, 0.0);
        }

        long start_time = System.currentTimeMillis();
        int total_num_errors = 0;

        int[] message = new int[22 * Zc];
        boolean rand_bool;
        int rand_int;
        int[] codeword = new int[68 * Zc];
        int check;
        int[] symbol = new int[68 * Zc];
        double[] r = new double[68 * Zc];
        double noise;
        double scaled_noise;
        double[] Beliefs = new double[68 * Zc];
        double[][] row_processing_storage = new double[Num_of_non_minus_1s][Zc];
        for (double[] row : row_processing_storage)
            Arrays.fill(row, 0.0);


        double total_num_iters = 0;
        for (int i = 0; i < num_blocks; i++) {
            Random rand1 = new Random();
            for (int p = 0; p < 22 * Zc; p++) {
                rand_bool = rand1.nextBoolean();
                rand_int = rand_bool ? 1 : 0;
                message[p] = rand_int;
            }

            codeword = encode_message(base_mat, Zc, message);
            check = check_codeword(base_mat, Zc, codeword);
            // System.out.println("check: " + check);

            for (int p = 0; p < 68 * Zc; p++) {
                symbol[p] = 1 - 2 * codeword[p];
            }

            Random rand2 = new Random();
            for (int p = 0; p < 68 * Zc; p++) {
                noise = rand2.nextGaussian();
                scaled_noise = sigma * noise;
                // System.out.println("scaled_noise: " + scaled_noise);
                r[p] = symbol[p] + scaled_noise;
            }

            /////////////////////////////// decoding ///////////////////////////////
            Beliefs = Arrays.copyOfRange(r, 0, 68 * Zc);
            for (double[] row : row_processing_storage) {
                Arrays.fill(row, 0.0);
                // System.out.println(Arrays.toString(row));
            }
            int rows_per_layer = (int) (num_rows) / num_layers;

            //////////////// iterations //////////////////
            int row_index;
            int col_index;

            int iteration_count = 0;
            boolean f_stop_val = false;
            boolean broke_out = false;
            while (iteration_count < max_number_of_iters){
                if (f_stop_val == true){
                    if (iteration_count > min_number_of_iters){
                        total_num_iters = total_num_iters + iteration_count;
                        broke_out = true;
                        break;
                    }
                }

            // for (int iteration_count = 0; iteration_count < num_iterations; iteration_count++) {
                row_index = 0;
                for (int layer_num = 0; layer_num < num_layers; layer_num++) {
                    int index1 = layer_num * rows_per_layer;
                    int index2 = (index1 + rows_per_layer);
                    for (int current_row_num = index1; current_row_num < index2; current_row_num++) {
                        col_index = 0;
                        int num_non_minus_1s_indexes = 0;
                        int val1 = 0;
                        for (int p = 0; p < 68; p++) {
                            val1 = base_mat[current_row_num][p];
                            if (val1 != -1) {
                                num_non_minus_1s_indexes++;
                            }
                        }
                        int[] non_minus_1s_indexes = new int[num_non_minus_1s_indexes];
                        int counter3 = 0;
                        for (int p = 0; p < 68; p++) {
                            val1 = base_mat[current_row_num][p];
                            if (val1 != -1) {
                                non_minus_1s_indexes[counter3] = p;
                                counter3++;
                            }
                        }
                        for (int columns : non_minus_1s_indexes) {
                            int count4 = 0;
                            for (int p = (columns) * Zc; p < (columns + 1) * Zc; p++) {
                                Beliefs[p] = Beliefs[p] - row_processing_storage[row_index][count4];
                                count4++;
                            }
                            double[] a = new double[Zc];
                            a = Arrays.copyOfRange(Beliefs, (columns) * Zc, (columns + 1) * Zc);
                            double[] b = new double[Zc];
                            b = shift_arr_db(a, base_mat[current_row_num][columns]);
                            for (int p = 0; p < Zc; p++) {
                                minsum_storage[p][col_index] = b[p];
                            }
                            col_index++;
                            row_index++;
                        }

                        for (int i1 = 0; i1 < Zc; i1++) {
                            double[] temp_arr = new double[col_index];
                            temp_arr = Arrays.copyOfRange(minsum_storage[i1], 0, col_index);
                            double min_val_1 = 100000.0;
                            double min_val_2 = 100001.0;
                            double val2 = 0;
                            double val3 = 0;
                            int pos1 = 10000000;
                            int[] sign = new int[col_index];
                            int overall_parity = 1;
                            for (int p = 0; p < col_index; p++) {
                                val2 = Math.abs(temp_arr[p]);
                                if (val2 <= min_val_1) { // val2 <= min_val_1
                                    min_val_2 = min_val_1;
                                    min_val_1 = val2;
                                    pos1 = p;
                                } else if (val2 > min_val_1 && val2 <= min_val_2) { // min_val_1 < val2 <= min_val_2
                                    min_val_2 = val2;
                                } else if (val2 > min_val_2) {
                                    ;
                                }
                                val3 = temp_arr[p];
                                if (val3 < 0) {
                                    overall_parity = overall_parity * (-1);
                                    sign[p] = -1;
                                } else {
                                    sign[p] = 1;
                                }
                            }
                            min_val_1 = min_val_1 - offset;
                            if (min_val_1 < 0) {
                                min_val_1 = 0;
                            }
                            min_val_2 = min_val_2 - offset;
                            if (min_val_2 < 0) {
                                min_val_2 = 0;
                            }
                            ////////////////////
                            double[] new_temp_reg = new double[col_index];
                            for (int p = 0; p < col_index; p++) {
                                new_temp_reg[p] = min_val_1;
                            }
                            new_temp_reg[pos1] = min_val_2;
                            for (int p = 0; p < col_index; p++) {
                                new_temp_reg[p] = new_temp_reg[p] * sign[p] * overall_parity;
                            }
                            temp_arr = new_temp_reg;
                            for (int p = 0; p < col_index; p++) {
                                minsum_storage[i1][p] = temp_arr[p];
                            }

                        }
                        row_index = row_index - col_index;
                        col_index = 0;

                        for (int columns : non_minus_1s_indexes) {
                            double[] a = new double[Zc];
                            for (int p = 0; p < Zc; p++) {
                                a[p] = minsum_storage[p][col_index];
                            }
                            double[] b = new double[Zc];
                            b = shift_arr_db(a, Zc - base_mat[current_row_num][columns]);
                            row_processing_storage[row_index] = Arrays.copyOfRange(b, 0, Zc);

                            int count4 = 0;
                            for (int p = (columns) * Zc; p < (columns + 1) * Zc; p++) {
                                Beliefs[p] = Beliefs[p] + row_processing_storage[row_index][count4];
                                count4++;
                            }
                            col_index++;
                            row_index++;
                        }
                    }
                }
                f_stop_val = threshold_test(Beliefs, threshold_value, n);
                iteration_count++; // increment while loop
                
            } // end of iterations
            if (broke_out == false){
                total_num_iters = total_num_iters + iteration_count;
            }

            double[] final_beliefs = new double[68 * Zc];
            final_beliefs = Beliefs;
            int[] decoded_message = new int[22 * Zc];
            decoded_message = decode_to_binary(final_beliefs, k);
            int errors_in_block = count_errors(message, decoded_message, k);
            total_num_errors = total_num_errors + errors_in_block;
        } // end of blocks

        int total_num_message_bits = num_blocks * k;
        double avg_num_iters = total_num_iters/num_blocks;
        double BER = (double) total_num_errors / total_num_message_bits;


        System.out.println("##############################################################");
        System.out.println("num_blocks =\t\t" + num_blocks);
        System.out.println("distance_away =\t\t" + distance_away);
        System.out.println("BER =\t\t\t\t" + BER);
        System.out.println("");
        System.out.println("threshold_value =\t" + threshold_value);
        System.out.println("iterations range =\t(" + min_number_of_iters+";"+ max_number_of_iters+")");
        System.out.println("avg_num_iters =\t\t" + avg_num_iters);
        long end_time = System.currentTimeMillis();
        long run_time = end_time - start_time;
        System.out.println("\navg_run_time =\t\t" + run_time/num_blocks+ " millisec");
        System.out.println("total_run_time =\t" + run_time / 1000 + " sec");
        System.out.println("##############################################################\n");
    }

    //////////////////////////// helper functions //////////////////////////
    public static boolean threshold_test(double[] array, double threshold_val, int n){
        boolean f_stop_val = true;
        for (int i = 0; i < n; i++){
            double val = Math.abs(array[i]);
            if (val < threshold_val){
                f_stop_val = false;
                break;
            }
        }
        return f_stop_val;
    }


    public static int check_codeword(int[][] base_mat, int Zc, int[] c) {
        // c[69] = 0; // break codeword for testing

        int check = 0;
        int num_rows = 46;
        int num_cols = 68;
        int[][] syndrome = new int[num_rows * Zc][1];
        for (int[] row : syndrome)
            Arrays.fill(row, 0);
        int[][] trans_val = new int[Zc][1];
        for (int[] row : trans_val)
            Arrays.fill(row, 0);
        int count = 0;
        for (int i = 0; i < num_rows; i++) {
            for (int j = 0; j < num_cols; j++) {
                int[] a = new int[Zc];
                a = Arrays.copyOfRange(c, (j) * Zc, (j + 1) * Zc);
                int[] b = new int[Zc];
                b = shift_arr_int(a, base_mat[i][j]);
                for (int k = 0; k < Zc; k++) {
                    trans_val[k][0] = b[k];
                }
                int count1 = 0;
                for (int k = i * Zc; k < (i + 1) * Zc; k++) {
                    syndrome[k][0] = syndrome[k][0] ^ trans_val[count1][0];
                    count1++;
                }
            }
        }
        int val = 0;
        for (int i = 0; i < num_rows * Zc; i++) {
            val = syndrome[i][0];
            if (val != 0) {
                System.out.println("error with codeword at: " + i);
                check = 1;
                break;
            }
        }
        return check;
    }

    public static int[] encode_message(int[][] base_mat, int Zc, int[] message) throws IOException {
        int num_rows = 46;
        int num_cols = 68;
        int[] codeword = new int[68 * Zc];
        Arrays.fill(codeword, 0);
        for (int x = 0; x < 22 * Zc; x++) {
            codeword[x] = message[x];
        }
        // P1 encoding
        int[] parity_mat = new int[Zc];
        Arrays.fill(parity_mat, 0);
        for (int x = 0; x < 4; x++) {
            for (int y = 0; y < (num_cols - num_rows); y++) {
                int[] a = new int[Zc];
                a = Arrays.copyOfRange(message, (y) * Zc, (y + 1) * Zc);
                int[] b = new int[Zc];
                b = shift_arr_int(a, base_mat[x][y]);
                for (int k = 0; k < Zc; k++) {
                    parity_mat[k] = parity_mat[k] ^ b[k];
                }
            }
        }
        int var;
        if (base_mat[1][num_cols - num_rows] == -1) {
            var = base_mat[2][num_cols - num_rows];
        } else {
            var = base_mat[1][num_cols - num_rows];
        }
        int[] c = new int[Zc];
        c = shift_arr_int(parity_mat, Zc - var); // p1
        int counter = 0;
        for (int x = (num_cols - num_rows) * Zc; x < (num_cols - num_rows + 1) * Zc; x++) {
            codeword[x] = c[counter];
            counter++;
        }

        // Find p2, p3, p4
        for (int x = 0; x < 3; x++) {
            Arrays.fill(parity_mat, 0);
            for (int y = 0; y < (num_cols - num_rows + x + 1); y++) {
                int[] a = new int[Zc];
                a = Arrays.copyOfRange(codeword, (y) * Zc, (y + 1) * Zc);
                int[] b = new int[Zc];
                b = shift_arr_int(a, base_mat[x][y]);
                for (int k = 0; k < Zc; k++) {
                    parity_mat[k] = parity_mat[k] ^ b[k];
                }
            }
            counter = 0;
            for (int p = (num_cols - num_rows + x + 1) * Zc; p < (num_cols - num_rows + x + 2) * Zc; p++) {
                codeword[p] = parity_mat[counter];
                counter++;
            }
        }

        // Find p5->end
        for (int x = 4; x < num_rows; x++) {
            Arrays.fill(parity_mat, 0);
            for (int y = 0; y < (num_cols - num_rows + 4); y++) {
                int[] a = new int[Zc];
                a = Arrays.copyOfRange(codeword, (y) * Zc, (y + 1) * Zc);
                int[] b = new int[Zc];
                b = shift_arr_int(a, base_mat[x][y]);
                for (int k = 0; k < Zc; k++) {
                    parity_mat[k] = parity_mat[k] ^ b[k];
                }
            }
            counter = 0;
            for (int p = (num_cols - num_rows + x) * Zc; p < (num_cols - num_rows + x + 1) * Zc; p++) {
                codeword[p] = parity_mat[counter];
                counter++;
            }
        }
        return codeword;
    }

    public static int[][] read_base_matrix(String base_mat_name) throws FileNotFoundException {
        int[][] temp_mat = new int[46][68];
        for (int[] row : temp_mat) {
            Arrays.fill(row, 0);
        }
        Path currentRelativePath = Paths.get("");
        String s = currentRelativePath.toAbsolutePath().toString() + "/";
        String file_dir = s;
        String file_name = base_mat_name;
        String whole_dir = file_dir + file_name;
        File fileName = new File(whole_dir);
        if (fileName.exists()) {
            // System.out.println("File name: " + fileName.getName());
            // System.out.println("Absolute path: " + fileName.getAbsolutePath());
        } else {
            System.out.println("The file does not exist.");
        }
        Scanner scFile = new Scanner(fileName);
        int lineNumber = 0;
        while (scFile.hasNextLine()) {
            String line = scFile.nextLine();
            // System.out.println("line " + lineNumber + " :" + line);
            // System.out.println(line);
            Scanner scLine = new Scanner(line);
            int rowNumber = 0;
            while (scLine.hasNextInt()) {
                temp_mat[lineNumber][rowNumber] = scLine.nextInt();
                rowNumber++;
            }
            lineNumber++;
        }
        return temp_mat;
    }

    public static int[] decode_to_binary(double[] final_beliefs, int k) {
        int temp_mat[] = new int[final_beliefs.length];
        Arrays.fill(temp_mat, 0);
        for (int i = 0; i < final_beliefs.length; i++) {
            if (final_beliefs[i] < 0) {
                temp_mat[i] = 1;
            } else {
                temp_mat[i] = 0;
            }
        }
        return temp_mat;
    }

    public static int count_errors(int[] encoded, int[] decoded, int k) {
        int error_count = 0;
        for (int i = 0; i < k; i++) {
            if (encoded[i] != decoded[i]) {
                error_count++;
            }
        }
        return error_count;
    }

    public static int[] shift_arr_int(int[] row, int x) {
        int arr[] = new int[row.length];
        Arrays.fill(arr, 0);
        if (x != -1) {
            int count = 0;
            for (int i = x; i < row.length; i++) {
                arr[count] = row[i];
                count += 1;
            }
            for (int i = 0; i < x; i++) {
                arr[count] = row[i];
                count += 1;
            }
        }
        return arr;
    }

    public static double[] shift_arr_db(double[] row, int x) {
        double arr[] = new double[row.length];
        Arrays.fill(arr, 0.0);
        if (x != -1) {
            int count = 0;
            for (int i = x; i < row.length; i++) {
                arr[count] = row[i];
                count += 1;
            }
            for (int i = 0; i < x; i++) {
                arr[count] = row[i];
                count += 1;
            }
        }
        return arr;
    }
}