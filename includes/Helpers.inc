<?php
/**
 * Created by PhpStorm.
 * User: beramos
 * Date: 6/22/18
 * Time: 10:15 PM
 */


/**
 * Function Called on batch finish
 *
 * @param $success
 * @param $results
 * @param $operations
 */
function _exemple_batch_multi_operation_batch_finished($success, $results, $operations) {
  if ($success) {
    drupal_set_message(t('Batch is complete'));
  }
  else {
    $error_operation = reset($operations);
    $message         = t('An error occurred while processing %error_operation with arguments: @arguments', array(
      '%error_operation' => $error_operation[0],
      '@arguments'       => print_r($error_operation[1], TRUE),
    ));
    drupal_set_message($message, 'error');
  }
}

/**
 *
 * Function Called on processing of first operation
 *
 * @param $data_operation_1
 * @param $progress1
 * @param $limit1
 * @param $context
 */
function exemple_batch_multi_operation_op1_process($data_operation_1, $progress1, $limit1, &$context) {
  //- Extract a slice of the data array  from $progress1 with $limit1 length
  $sliced_data = array_slice($data_operation_1, $progress1, $limit1);
  foreach ($sliced_data as $data) {
    //- Do what you want with your data here
  }
  //- update progress for message
  $progress1 = $progress1 + $limit1;
  //- update message during each run so you know where you are in the process
  $context['message'] = 'Now First Processing ' . $progress1 . ' - ' . $context['results'][0] . ' Processed';
}

/**
 * Function Called on processing of second operation
 *
 * @param $data_operation_2
 * @param $progress2
 * @param $limit2
 * @param $context
 */
function exemple_batch_multi_operation_op2_process($data_operation_2, $progress2, $limit2, &$context) {
  //- Extract a slice of the $records array  from $progress2 with $limit2 length
  $sliced_data = array_slice($data_operation_2, $progress2, $limit2);
  foreach ($sliced_data as $data) {
    //- Do what you want with your data here
  }
  //- update progress for message
  $progress1 = $progress2 + $limit2;
  //- update message during each run so you know where you are in the process
  $context['message'] = 'Now Second Processing ' . $progress1 . ' - ' . $context['results'][0] . ' Processed';
}

/**
 * Helper Function to populate array for test
 *
 * @note: you can populate with any data using db_select or what ever ....
 *
 * @param $n
 *
 * @return array
 */
function populate_array_for_test($n) {
  $res = array();
  for ($i = 0; $i < $n; $i++) {
    $res [] = $i + 1;
  }
  return $res;
}
