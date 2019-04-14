
# include <Siv3D.hpp>

void Main()
{
	const Font font(30);

	Window::SetTitle(L"Breath of the Modal");

	Graphics::SetBackground(Palette::Darkgray);

	while (System::Update())
	{
		Graphics3D::FreeCamera();

		for (int i = 0; i < 128; ++i)
		{
			const double basis = 2.0*Pi / 128.0;
			const double a = basis * i;
			const double b = basis * (i + 1);

			const auto xa = Vec3(0.0, Sin(a), Cos(a));
			const auto xb = Vec3(0.0, Sin(b), Cos(b));
			const auto za = Vec3(Cos(a), Sin(a), 0.0);
			const auto zb = Vec3(Cos(b), Sin(b), 0.0);
			const auto ya = Vec3(Sin(a), 0.0, Cos(a));
			const auto yb = Vec3(Sin(b), 0.0, Cos(b));

			Line3D(xa, xb).drawForward(Palette::Red);
			Line3D(ya, yb).drawForward(Palette::Green);
			Line3D(za, zb).drawForward(Palette::Blue);
		}

		const auto origin = Vec3(0.0, 0.0, 0.0);
		Line3D(origin, Vec3(1.0, 0.0, 0.0)).drawForward(Palette::Red);
		Line3D(origin, Vec3(0.0, 1.0, 0.0)).drawForward(Palette::Green);
		Line3D(origin, Vec3(0.0, 0.0, 1.0)).drawForward(Palette::Blue);
	}
}
