package deps.implementations

import deps.versions.Framework

object Framework {
    // Jetpack Deps
    const val navFragment = "androidx.navigation:navigation-fragment-ktx:${Framework.navComponents}"
    const val navRuntime = "androidx.navigation:navigation-runtime:${Framework.navComponents}"
    const val navUi = "androidx.navigation:navigation-ui-ktx:${Framework.navComponents}"
    const val navDynamic = "androidx.navigation:navigation-dynamic-features-fragment:${Framework.navComponents}"

    // Core deps
    const val appCompat = "androidx.appcompat:appcompat:${Framework.appCompat}"
    const val constraintLayout = "androidx.constraintlayout:constraintlayout:${Framework.constraintLayout}"
    const val materialDesign = "com.google.android.material:material:${Framework.materialDesign}"
    const val swipeRefreshLayout = "androidx.swiperefreshlayout:swiperefreshlayout:${Framework.swipeRefreshLayout}"

    //Lifecycle handling
//    const val lifecycleRuntime = "androidx.lifecycle:lifecycle-runtime:${Framework.lifecycleVersion}"
//    const val lifecycleCoRoutines = "androidx.lifecycle:lifecycle-livedata-ktx:${Framework.lifecycleVersion}"
}
