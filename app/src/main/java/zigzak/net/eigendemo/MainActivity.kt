package zigzak.net.eigendemo

import android.os.Bundle
import android.support.v7.app.AppCompatActivity
import kotlinx.android.synthetic.main.activity_main.*

class MainActivity : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        // Example of a call to a native method
        sample_text.text = computeDeterminant().toString()
        println(test(arrayOf(0,1,2,3,4,5,6,7)))
        val test = test2(arrayOf(0,1,2,3,4,5,6,7))
        test.forEach {
            println(it)
        }
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    private external fun computeDeterminant() : Double

    private external fun computeSelfAdjointEigen(): Float

    private external fun test(arr: Array<Int>): Int

    private external fun test2(arr: Array<Int>): Array<Int>


    companion object {

        // Used to load the 'native-lib' library on application startup.
        init {
            System.loadLibrary("native-lib")
        }
    }
}
