import math

def calibration_least_squares(T_meas, T_ref):
    """
    T_meas : liste des valeurs capteur
    T_ref  : liste des valeurs reference
    """
    N = len(T_meas)
    if N != len(T_ref):
        raise ValueError("The two lists must have the same length.")
    if N < 3:
        raise ValueError("At least 3 points needed to compute uncertainties.")
    
    # ---- Calcul des sommes ----
    Sx   = sum(T_meas)
    Sy   = sum(T_ref)
    Sxx  = sum(x*x for x in T_meas)
    Sxy  = sum(T_meas[i] * T_ref[i] for i in range(N))

    # ---- Déterminant Δ ----
    Delta = N * Sxx - Sx**2

    # ---- Coefficients a et b ----
    a = (N * Sxy - Sx * Sy) / Delta
    b = (Sxx * Sy - Sx * Sxy) / Delta

    # ---- Calcul des résidus ----
    residuals = [T_ref[i] - (a * T_meas[i] + b) for i in range(N)]
    
    # ---- Variance des résidus ----
    sigma2 = sum(r*r for r in residuals) / (N - 2)
    sigma = math.sqrt(sigma2)  # = u_fit

    # ---- Incertitudes sur a et b ----
    sigma_a = math.sqrt(sigma2 * N / Delta)
    sigma_b = math.sqrt(sigma2 * Sxx / Delta)

    # ---- Covariance(a,b) ----
    cov_ab = -Sx * sigma2 / Delta

    # ---- Coefficient de corrélation r ----
    r = cov_ab / (sigma_a * sigma_b)

    return a, b, sigma_a, sigma_b, sigma2, sigma, cov_ab, r, residuals


def corrected_value_with_uncertainty(Tm, a, b, ua, ub, ufit, r):
    """
    Calcule Tcorr = a*Tm + b et l'incertitude composée u_c
    """
    # Formule GUM :
    # u_c^2 = (Tm*ua)^2 + ub^2 + 2*Tm*r*ua*ub + ufit^2
    uc2 = (Tm*ua)**2 + ub**2 + 2*Tm*r*ua*ub + ufit**2
    uc = math.sqrt(uc2)
    Tc = a*Tm + b
    return Tc, uc


# -------------------------------
# Exemple d'utilisation
# -------------------------------
if __name__ == "__main__":

    # Exemple de données
    T_meas = [0.164, 0.712, 1.288]  # capteur
    T_ref  = [0.25, 1.25, 2.25]     # reference

    a, b, ua, ub, sigma2, ufit, cov_ab, r, residuals = calibration_least_squares(T_meas, T_ref)

    print("a =", a)
    print("b =", b)
    print("u(a) =", ua)
    print("u(b) =", ub)
    # ufit is a measure of the overall uncertainty of the fit, u_fit correspond to the standard deviation of the residuals
    print("u_fit (sigma) =", ufit)
    print("cov(a,b) =", cov_ab)
    print("Correlation r =", r)
    print("Residual variance sigma² =", sigma2)
    print("Residuals =", residuals)

    # Exemple de correction d'une valeur
    T_meas_new = 0.288
    T_corr, u_corr = corrected_value_with_uncertainty(
        T_meas_new, a, b, ua, ub, ufit, r
    )

    print(f"\nCorrected T for T_meas={T_meas_new} :", T_corr)
    print(f"Uncertainty u_c for T_meas={T_meas_new} :", u_corr)
