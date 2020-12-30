package com.example.myapplication;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.text.Editable;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
        //System.loadLibrary("Operation");
       // System.loadLibrary("test");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Example of a call to a native method

        final TextView result=findViewById(R.id.result);
        final EditText inputtext=findViewById(R.id.inputtext);

        Button calculation=findViewById(R.id.calculation);

        calculation.setOnClickListener(new View.OnClickListener() {
                    @Override
                    public void onClick(View view) {
                        Editable edit_input=inputtext.getText();
                        String fomula_text=edit_input.toString(); //공식
                        result.setText(editTextFromJNI(fomula_text));
            }
        });
    }
/**
 * A native method that is implemented by the 'native-lib' native library,
 * which is packaged with this application.
 */
    public native String editTextFromJNI(String str);

}